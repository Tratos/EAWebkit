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

#include "JSTextEvent.h"

#include <wtf/GetPtr.h>

#include "JSDOMWindow.h"
#include "KURL.h"
#include "TextEvent.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSTextEventTableValues[3] =
{
    { "data", (intptr_t)JSTextEvent::DataAttrNum, DontDelete|ReadOnly, 0 },
    { "constructor", (intptr_t)JSTextEvent::ConstructorAttrNum, DontEnum, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSTextEventTable = { 3, JSTextEventTableValues, 0 };

/* Hash table for constructor */

static const HashTableValue JSTextEventConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSTextEventConstructorTable = { 0, JSTextEventConstructorTableValues, 0 };

class JSTextEventConstructor : public DOMObject {
public:
    JSTextEventConstructor(ExecState* exec)
        : DOMObject(exec->lexicalGlobalObject()->objectPrototype())
    {
        putDirect(exec->propertyNames().prototype, JSTextEventPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSTextEventConstructor::s_info = { "TextEventConstructor", 0, &JSTextEventConstructorTable, 0 };

bool JSTextEventConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTextEventConstructor, DOMObject>(exec, &JSTextEventConstructorTable, this, propertyName, slot);
}

JSValue* JSTextEventConstructor::getValueProperty(ExecState* exec, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(exec, token);
}

/* Hash table for prototype */

static const HashTableValue JSTextEventPrototypeTableValues[2] =
{
    { "initTextEvent", (intptr_t)jsTextEventPrototypeFunctionInitTextEvent, DontDelete|Function, 5 },
    { 0, 0, 0, 0 }
};

static const HashTable JSTextEventPrototypeTable = { 0, JSTextEventPrototypeTableValues, 0 };

const ClassInfo JSTextEventPrototype::s_info = { "TextEventPrototype", 0, &JSTextEventPrototypeTable, 0 };

JSObject* JSTextEventPrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSTextEvent.prototype]]");
    return KJS::cacheGlobalObject<JSTextEventPrototype>(exec, prototypeIdentifier);
}

bool JSTextEventPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSTextEventPrototypeTable, this, propertyName, slot);
}

const ClassInfo JSTextEvent::s_info = { "TextEvent", &JSUIEvent::s_info, &JSTextEventTable , 0 };

JSTextEvent::JSTextEvent(JSObject* prototype, TextEvent* impl)
    : JSUIEvent(prototype, impl)
{
}

bool JSTextEvent::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTextEvent, Base>(exec, &JSTextEventTable, this, propertyName, slot);
}

JSValue* JSTextEvent::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case DataAttrNum: {
        TextEvent* imp = static_cast<TextEvent*>(impl());
        return jsString(exec, imp->data());
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

JSValue* JSTextEvent::getConstructor(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier constructorIdentifier(exec, "[[TextEvent.constructor]]");
    return KJS::cacheGlobalObject<JSTextEventConstructor>(exec, constructorIdentifier);
}

JSValue* jsTextEventPrototypeFunctionInitTextEvent(ExecState* exec, JSObject*, JSValue* thisValue, const ArgList& args)
{
    if (!thisValue->isObject(&JSTextEvent::s_info))
        return throwError(exec, TypeError);
    JSTextEvent* castedThisObj = static_cast<JSTextEvent*>(thisValue);
    TextEvent* imp = static_cast<TextEvent*>(castedThisObj->impl());
    const UString& typeArg = args[0]->toString(exec);
    bool canBubbleArg = args[1]->toBoolean(exec);
    bool cancelableArg = args[2]->toBoolean(exec);
    DOMWindow* viewArg = toDOMWindow(args[3]);
    const UString& dataArg = args[4]->toString(exec);

    imp->initTextEvent(typeArg, canBubbleArg, cancelableArg, viewArg, dataArg);
    return jsUndefined();
}


}
