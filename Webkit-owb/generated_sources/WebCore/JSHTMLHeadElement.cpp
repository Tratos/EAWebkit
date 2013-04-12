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

#include "JSHTMLHeadElement.h"

#include <wtf/GetPtr.h>

#include "HTMLHeadElement.h"
#include "KURL.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSHTMLHeadElementTableValues[3] =
{
    { "profile", (intptr_t)JSHTMLHeadElement::ProfileAttrNum, DontDelete, 0 },
    { "constructor", (intptr_t)JSHTMLHeadElement::ConstructorAttrNum, DontEnum, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSHTMLHeadElementTable = { 7, JSHTMLHeadElementTableValues, 0 };

/* Hash table for constructor */

static const HashTableValue JSHTMLHeadElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSHTMLHeadElementConstructorTable = { 0, JSHTMLHeadElementConstructorTableValues, 0 };

class JSHTMLHeadElementConstructor : public DOMObject {
public:
    JSHTMLHeadElementConstructor(ExecState* exec)
        : DOMObject(exec->lexicalGlobalObject()->objectPrototype())
    {
        putDirect(exec->propertyNames().prototype, JSHTMLHeadElementPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSHTMLHeadElementConstructor::s_info = { "HTMLHeadElementConstructor", 0, &JSHTMLHeadElementConstructorTable, 0 };

bool JSHTMLHeadElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLHeadElementConstructor, DOMObject>(exec, &JSHTMLHeadElementConstructorTable, this, propertyName, slot);
}

JSValue* JSHTMLHeadElementConstructor::getValueProperty(ExecState* exec, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(exec, token);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLHeadElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSHTMLHeadElementPrototypeTable = { 0, JSHTMLHeadElementPrototypeTableValues, 0 };

const ClassInfo JSHTMLHeadElementPrototype::s_info = { "HTMLHeadElementPrototype", 0, &JSHTMLHeadElementPrototypeTable, 0 };

JSObject* JSHTMLHeadElementPrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSHTMLHeadElement.prototype]]");
    return KJS::cacheGlobalObject<JSHTMLHeadElementPrototype>(exec, prototypeIdentifier);
}

const ClassInfo JSHTMLHeadElement::s_info = { "HTMLHeadElement", &JSHTMLElement::s_info, &JSHTMLHeadElementTable , 0 };

JSHTMLHeadElement::JSHTMLHeadElement(JSObject* prototype, HTMLHeadElement* impl)
    : JSHTMLElement(prototype, impl)
{
}

bool JSHTMLHeadElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLHeadElement, Base>(exec, &JSHTMLHeadElementTable, this, propertyName, slot);
}

JSValue* JSHTMLHeadElement::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case ProfileAttrNum: {
        HTMLHeadElement* imp = static_cast<HTMLHeadElement*>(impl());
        return jsString(exec, imp->profile());
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

void JSHTMLHeadElement::put(ExecState* exec, const Identifier& propertyName, JSValue* value)
{
    lookupPut<JSHTMLHeadElement, Base>(exec, propertyName, value, &JSHTMLHeadElementTable, this);
}

void JSHTMLHeadElement::putValueProperty(ExecState* exec, int token, JSValue* value)
{
    switch (token) {
    case ProfileAttrNum: {
        HTMLHeadElement* imp = static_cast<HTMLHeadElement*>(impl());
        imp->setProfile(valueToStringWithNullCheck(exec, value));
        break;
    }
    }
}

JSValue* JSHTMLHeadElement::getConstructor(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier constructorIdentifier(exec, "[[HTMLHeadElement.constructor]]");
    return KJS::cacheGlobalObject<JSHTMLHeadElementConstructor>(exec, constructorIdentifier);
}


}
