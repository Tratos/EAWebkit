/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

/*
* This file was modified by Electronic Arts Inc Copyright � 2009-2010
*/

#include "config.h"

#include "JSCharacterData.h"

#include <wtf/GetPtr.h>

#include "CharacterData.h"
#include "ExceptionCode.h"
#include "KURL.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSCharacterDataTableValues[4] =
{
    { "data", (intptr_t)JSCharacterData::DataAttrNum, DontDelete, 0 },
    { "length", (intptr_t)JSCharacterData::LengthAttrNum, DontDelete|ReadOnly, 0 },
    { "constructor", (intptr_t)JSCharacterData::ConstructorAttrNum, DontEnum, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSCharacterDataTable = { 15, JSCharacterDataTableValues, 0 };

/* Hash table for constructor */

static const HashTableValue JSCharacterDataConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSCharacterDataConstructorTable = { 0, JSCharacterDataConstructorTableValues, 0 };

class JSCharacterDataConstructor : public DOMObject {
public:
    JSCharacterDataConstructor(ExecState* exec)
        : DOMObject(exec->lexicalGlobalObject()->objectPrototype())
    {
        putDirect(exec->propertyNames().prototype, JSCharacterDataPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSCharacterDataConstructor::s_info = { "CharacterDataConstructor", 0, &JSCharacterDataConstructorTable, 0 };

bool JSCharacterDataConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCharacterDataConstructor, DOMObject>(exec, &JSCharacterDataConstructorTable, this, propertyName, slot);
}

JSValue* JSCharacterDataConstructor::getValueProperty(ExecState* exec, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(exec, token);
}

/* Hash table for prototype */

static const HashTableValue JSCharacterDataPrototypeTableValues[6] =
{
    { "substringData", (intptr_t)jsCharacterDataPrototypeFunctionSubstringData, DontDelete|Function, 2 },
    { "appendData", (intptr_t)jsCharacterDataPrototypeFunctionAppendData, DontDelete|Function, 1 },
    { "insertData", (intptr_t)jsCharacterDataPrototypeFunctionInsertData, DontDelete|Function, 2 },
    { "deleteData", (intptr_t)jsCharacterDataPrototypeFunctionDeleteData, DontDelete|Function, 2 },
    { "replaceData", (intptr_t)jsCharacterDataPrototypeFunctionReplaceData, DontDelete|Function, 3 },
    { 0, 0, 0, 0 }
};

static const HashTable JSCharacterDataPrototypeTable = { 15, JSCharacterDataPrototypeTableValues, 0 };

const ClassInfo JSCharacterDataPrototype::s_info = { "CharacterDataPrototype", 0, &JSCharacterDataPrototypeTable, 0 };

JSObject* JSCharacterDataPrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSCharacterData.prototype]]");
    return KJS::cacheGlobalObject<JSCharacterDataPrototype>(exec, prototypeIdentifier);
}

bool JSCharacterDataPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSCharacterDataPrototypeTable, this, propertyName, slot);
}

const ClassInfo JSCharacterData::s_info = { "CharacterData", &JSEventTargetNode::s_info, &JSCharacterDataTable , 0 };

JSCharacterData::JSCharacterData(JSObject* prototype, CharacterData* impl)
    : JSEventTargetNode(prototype, impl)
{
}

bool JSCharacterData::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCharacterData, Base>(exec, &JSCharacterDataTable, this, propertyName, slot);
}

JSValue* JSCharacterData::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case DataAttrNum: {
        CharacterData* imp = static_cast<CharacterData*>(impl());
        return jsString(exec, imp->data());
    }
    case LengthAttrNum: {
        CharacterData* imp = static_cast<CharacterData*>(impl());
        return jsNumber(exec, imp->length());
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

void JSCharacterData::put(ExecState* exec, const Identifier& propertyName, JSValue* value)
{
    lookupPut<JSCharacterData, Base>(exec, propertyName, value, &JSCharacterDataTable, this);
}

void JSCharacterData::putValueProperty(ExecState* exec, int token, JSValue* value)
{
    switch (token) {
    case DataAttrNum: {
        CharacterData* imp = static_cast<CharacterData*>(impl());
        ExceptionCode ec = 0;
        imp->setData(valueToStringWithNullCheck(exec, value), ec);
        setDOMException(exec, ec);
        break;
    }
    }
}

JSValue* JSCharacterData::getConstructor(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier constructorIdentifier(exec, "[[CharacterData.constructor]]");
    return KJS::cacheGlobalObject<JSCharacterDataConstructor>(exec, constructorIdentifier);
}

JSValue* jsCharacterDataPrototypeFunctionSubstringData(ExecState* exec, JSObject*, JSValue* thisValue, const ArgList& args)
{
    if (!thisValue->isObject(&JSCharacterData::s_info))
        return throwError(exec, TypeError);
    JSCharacterData* castedThisObj = static_cast<JSCharacterData*>(thisValue);
    CharacterData* imp = static_cast<CharacterData*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args[0]->toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }
    int length = args[1]->toInt32(exec);
    if (length < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }


    KJS::JSValue* result = jsStringOrNull(exec, imp->substringData(offset, length, ec));
    setDOMException(exec, ec);
    return result;
}

JSValue* jsCharacterDataPrototypeFunctionAppendData(ExecState* exec, JSObject*, JSValue* thisValue, const ArgList& args)
{
    if (!thisValue->isObject(&JSCharacterData::s_info))
        return throwError(exec, TypeError);
    JSCharacterData* castedThisObj = static_cast<JSCharacterData*>(thisValue);
    CharacterData* imp = static_cast<CharacterData*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    const UString& data = args[0]->toString(exec);

    imp->appendData(data, ec);
    setDOMException(exec, ec);
    return jsUndefined();
}

JSValue* jsCharacterDataPrototypeFunctionInsertData(ExecState* exec, JSObject*, JSValue* thisValue, const ArgList& args)
{
    if (!thisValue->isObject(&JSCharacterData::s_info))
        return throwError(exec, TypeError);
    JSCharacterData* castedThisObj = static_cast<JSCharacterData*>(thisValue);
    CharacterData* imp = static_cast<CharacterData*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args[0]->toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }
    const UString& data = args[1]->toString(exec);

    imp->insertData(offset, data, ec);
    setDOMException(exec, ec);
    return jsUndefined();
}

JSValue* jsCharacterDataPrototypeFunctionDeleteData(ExecState* exec, JSObject*, JSValue* thisValue, const ArgList& args)
{
    if (!thisValue->isObject(&JSCharacterData::s_info))
        return throwError(exec, TypeError);
    JSCharacterData* castedThisObj = static_cast<JSCharacterData*>(thisValue);
    CharacterData* imp = static_cast<CharacterData*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args[0]->toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }
    int length = args[1]->toInt32(exec);
    if (length < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }

    imp->deleteData(offset, length, ec);
    setDOMException(exec, ec);
    return jsUndefined();
}

JSValue* jsCharacterDataPrototypeFunctionReplaceData(ExecState* exec, JSObject*, JSValue* thisValue, const ArgList& args)
{
    if (!thisValue->isObject(&JSCharacterData::s_info))
        return throwError(exec, TypeError);
    JSCharacterData* castedThisObj = static_cast<JSCharacterData*>(thisValue);
    CharacterData* imp = static_cast<CharacterData*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args[0]->toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }
    int length = args[1]->toInt32(exec);
    if (length < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }
    const UString& data = args[2]->toString(exec);

    imp->replaceData(offset, length, data, ec);
    setDOMException(exec, ec);
    return jsUndefined();
}


}
