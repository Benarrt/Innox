#include "ixshadowtextfield.h"
#include "ixtextfield.h"

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

extern "C" {
        void EMSCRIPTEN_KEEPALIVE shadowTextFieldData(quint16 cursorPos, QChar* data)
        {
            QString k(data);
            free(data);
            IXShadowTextField::inst().shadowTextFieldData(cursorPos, k);
        }
}


IXShadowTextField::IXShadowTextField() : _textField(nullptr)
{
    EM_ASM({
        var input = document.createElement("input");
        document.body.appendChild(input);
        input.id = "shadowTextField";
        input.inputMode = "text";
        input.type = "text";
        input.hidden = true;
        input.style.opacity = 0;

        var inputEventHandler = function(e) {
           var selStart = e.target.selectionStart;
           var selEnd = e.target.selectionStart;
           var dataStr = this.value;
           var heapPtr = Module._malloc((dataStr.length+1)*2);
           Module.stringToUTF16(dataStr, heapPtr, (dataStr.length+1)*2);
           Module._shadowTextFieldData(selEnd < selStart ? selEnd : selStart, heapPtr);
        };

       var shadowInputElements = {};
       shadowInputElements.input = input;
       shadowInputElements.qtCanvas = document.getElementById("qtcanvas");

        window.focusShadowTextField = (function (currentValue) {
               this.qtCanvas.blur();
               this.input.hidden = false;
               this.input.focus({preventScroll:true});
               this.input.value = currentValue;
        }).bind(shadowInputElements);

        window.blurShadowTextField = (function () {
               this.input.blur();
               this.input.hidden = true;
               this.qtCanvas.focus();
               this.qtCanvas.scrollIntoView();
        }).bind(shadowInputElements);

       window.moveShadowTextFieldCursor = (function (pos) {
            console.log("moveShadowTextFieldCursor", pos);
            this.input.setSelectionRange(pos, pos);
       }).bind(shadowInputElements);

       input.addEventListener('input', inputEventHandler.bind(input));
       input.addEventListener('keydown', inputEventHandler.bind(input));
       input.addEventListener('keyup', inputEventHandler.bind(input));
    });
}

void IXShadowTextField::addTextField(IXTextField* textField)
{
    Q_ASSERT(_textField == nullptr);
    _textField = textField;
}
void IXShadowTextField::removeTextField(IXTextField* textField)
{
    Q_ASSERT(_textField == textField);
    _textField = nullptr;
}

void IXShadowTextField::shadowTextFieldData(quint16 cursorPos, const QString& data)
{
    Q_ASSERT(_textField != nullptr);
    if(!_textField)
        return;

    _textField->setTextValue(cursorPos, data);
}
