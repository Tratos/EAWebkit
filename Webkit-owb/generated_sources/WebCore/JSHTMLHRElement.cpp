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

#include "JSHTMLHRElement.h"

#include <wtf/GetPtr.h>

#include "HTMLHRElement.h"
#include "KURL.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSHTMLHRElementTableValues[6] =
{
    { "align", (intptr_t)JSHTMLHRElement::AlignAttrNum, DontDelete, 0 },
    { "noShade", (intptr_t)JSHTMLHRElement::NoShadeAttrNum, DontDelete, 0 },
    { "size", (intptr_t)JSHTMLHRElement::SizeAttrNum, DontDelete, 0 },
    { "width", (intptr_t)JSHTMLHRElement::WidthAttrNum, DontDelete, 0 },
    { "constructor", (intptr_t)JSHTMLHRElement::ConstructorAttrNum, DontEnum, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSHTMLHRElementTable = { 31, JSHTMLHRElementTableValues, 0 };

/* Hash table for constructor */

static const HashTableValue JSHTMLHRElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSHTMLHRElementConstructorTable = { 0, JSHTMLHRElementConstructorTableValues, 0 };

class JSHTMLHRElementConstructor : public DOMObject {
public:
    JSHTMLHRElementConstructor(ExecState* exec)
        : DOMObject(exec->lexicalGlobalObject()->objectPrototype())
    {
        putDirect(exec->propertyNames().prototype, JSHTMLHRElementPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSHTMLHRElementConstructor::s_info = { "HTMLHRElementConstructor", 0, &JSHTMLHRElementConstructorTable, 0 };

bool JSHTMLHRElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLHRElementConstructor, DOMObject>(exec, &JSHTMLHRElementConstructorTable, this, propertyName, slot);
}

JSValue* JSHTMLHRElementConstructor::getValueProperty(ExecState* exec, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(exec, token);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLHRElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSHTMLHRElementPrototypeTable = { 0, JSHTMLHRElementPrototypeTableValues, 0 };

const ClassInfo JSHTMLHRElementPrototype::s_info = { "HTMLHRElementPrototype", 0, &JSHTMLHRElementPrototypeTable, 0 };

JSObject* JSHTMLHRElementPrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSHTMLHRElement.prototype]]");
    return KJS::cacheGlobalObject<JSHTMLHRElementPrototype>(exec, prototypeIdentifier);
}

const ClassInfo JSHTMLHRElement::s_info = { "HTMLHRElement", &JSHTMLElement::s_info, &JSHTMLHRElementTable , 0 };

JSHTMLHRElement::JSHTMLHRElement(JSObject* prototype, HTMLHRElement* impl)
    : JSHTMLElement(prototype, impl)
{
}

bool JSHTMLHRElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLHRElement, Base>(exec, &JSHTMLHRElementTable, this, propertyName, slot);
}

JSValue* JSHTMLHRElement::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case AlignAttrNum: {
        HTMLHRElement* imp = static_cast<HTMLHRElement*>(impl());
        return jsString(exec, imp->align());
    }
    case NoShadeAttrNum: {
        HTMLHRElement* imp = static_cast<HTMLHRElement*>(impl());
        return jsBoolean(imp->noShade());
    }
    case SizeAttrNum: {
        HTMLHRElement* imp = static_cast<HTMLHRElement*>(impl());
        return jsString(exec, imp->size());
    }
    case WidthAttrNum: {
        HTMLHRElement* imp = static_cast<HTMLHRElement*>(impl());
        return jsString(exec, imp->width());
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

void JSHTMLHRElement::put(ExecState* exec, const Identifier& propertyName, JSValue* value)
{
    lookupPut<JSHTMLHRElement, Base>(exec, propertyName, value, &JSHTMLHRElementTable, this);
}

void JSHTMLHRElement::putValueProperty(ExecState* exec, int token, JSValue* value)
{
    switch (token) {
    case AlignAttrNum: {
        HTMLHRElement* imp = static_cast<HTMLHRElement*>(impl());
        imp->setAlign(valueToStringWithNullCheck(exec, value));
        break;
    }
    case NoShadeAttrNum: {
        HTMLHRElement* imp = static_cast<HTMLHRElement*>(impl());
        imp->setNoShade(value->toBoolean(exec));
        break;
    }
    case SizeAttrNum: {
        HTMLHRElement* imp = static_cast<HTMLHRElement*>(impl());
        imp->setSize(valueToStringWithNullCheck(exec, value));
        break;
    }
    case WidthAttrNum: {
        HTMLHRElement* imp = static_cast<HTMLHRElement*>(impl());
        imp->setWidth(valueToStringWithNullCheck(exec, value));
        break;
    }
    }
}

JSValue* JSHTMLHRElement::getConstructor(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier constructorIdentifier(exec, "[[HTMLHRElement.constructor]]");
    return KJS::cacheGlobalObject<JSHTMLHRElementConstructor>(exec, constructorIdentifier);
}


}
