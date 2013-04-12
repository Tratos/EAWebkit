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

#include "JSHTMLLinkElement.h"

#include <wtf/GetPtr.h>

#include "HTMLLinkElement.h"
#include "JSStyleSheet.h"
#include "KURL.h"
#include "StyleSheet.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSHTMLLinkElementTableValues[12] =
{
    { "disabled", (intptr_t)JSHTMLLinkElement::DisabledAttrNum, DontDelete, 0 },
    { "charset", (intptr_t)JSHTMLLinkElement::CharsetAttrNum, DontDelete, 0 },
    { "href", (intptr_t)JSHTMLLinkElement::HrefAttrNum, DontDelete, 0 },
    { "hreflang", (intptr_t)JSHTMLLinkElement::HreflangAttrNum, DontDelete, 0 },
    { "media", (intptr_t)JSHTMLLinkElement::MediaAttrNum, DontDelete, 0 },
    { "rel", (intptr_t)JSHTMLLinkElement::RelAttrNum, DontDelete, 0 },
    { "rev", (intptr_t)JSHTMLLinkElement::RevAttrNum, DontDelete, 0 },
    { "target", (intptr_t)JSHTMLLinkElement::TargetAttrNum, DontDelete, 0 },
    { "type", (intptr_t)JSHTMLLinkElement::TypeAttrNum, DontDelete, 0 },
    { "sheet", (intptr_t)JSHTMLLinkElement::SheetAttrNum, DontDelete|ReadOnly, 0 },
    { "constructor", (intptr_t)JSHTMLLinkElement::ConstructorAttrNum, DontEnum, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSHTMLLinkElementTable = { 63, JSHTMLLinkElementTableValues, 0 };

/* Hash table for constructor */

static const HashTableValue JSHTMLLinkElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSHTMLLinkElementConstructorTable = { 0, JSHTMLLinkElementConstructorTableValues, 0 };

class JSHTMLLinkElementConstructor : public DOMObject {
public:
    JSHTMLLinkElementConstructor(ExecState* exec)
        : DOMObject(exec->lexicalGlobalObject()->objectPrototype())
    {
        putDirect(exec->propertyNames().prototype, JSHTMLLinkElementPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSHTMLLinkElementConstructor::s_info = { "HTMLLinkElementConstructor", 0, &JSHTMLLinkElementConstructorTable, 0 };

bool JSHTMLLinkElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLLinkElementConstructor, DOMObject>(exec, &JSHTMLLinkElementConstructorTable, this, propertyName, slot);
}

JSValue* JSHTMLLinkElementConstructor::getValueProperty(ExecState* exec, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(exec, token);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLLinkElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSHTMLLinkElementPrototypeTable = { 0, JSHTMLLinkElementPrototypeTableValues, 0 };

const ClassInfo JSHTMLLinkElementPrototype::s_info = { "HTMLLinkElementPrototype", 0, &JSHTMLLinkElementPrototypeTable, 0 };

JSObject* JSHTMLLinkElementPrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSHTMLLinkElement.prototype]]");
    return KJS::cacheGlobalObject<JSHTMLLinkElementPrototype>(exec, prototypeIdentifier);
}

const ClassInfo JSHTMLLinkElement::s_info = { "HTMLLinkElement", &JSHTMLElement::s_info, &JSHTMLLinkElementTable , 0 };

JSHTMLLinkElement::JSHTMLLinkElement(JSObject* prototype, HTMLLinkElement* impl)
    : JSHTMLElement(prototype, impl)
{
}

bool JSHTMLLinkElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLLinkElement, Base>(exec, &JSHTMLLinkElementTable, this, propertyName, slot);
}

JSValue* JSHTMLLinkElement::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case DisabledAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        return jsBoolean(imp->disabled());
    }
    case CharsetAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        return jsString(exec, imp->charset());
    }
    case HrefAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        return jsString(exec, imp->href());
    }
    case HreflangAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        return jsString(exec, imp->hreflang());
    }
    case MediaAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        return jsString(exec, imp->media());
    }
    case RelAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        return jsString(exec, imp->rel());
    }
    case RevAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        return jsString(exec, imp->rev());
    }
    case TargetAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        return jsString(exec, imp->target());
    }
    case TypeAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        return jsString(exec, imp->type());
    }
    case SheetAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        return toJS(exec, WTF::getPtr(imp->sheet()));
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

void JSHTMLLinkElement::put(ExecState* exec, const Identifier& propertyName, JSValue* value)
{
    lookupPut<JSHTMLLinkElement, Base>(exec, propertyName, value, &JSHTMLLinkElementTable, this);
}

void JSHTMLLinkElement::putValueProperty(ExecState* exec, int token, JSValue* value)
{
    switch (token) {
    case DisabledAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        imp->setDisabled(value->toBoolean(exec));
        break;
    }
    case CharsetAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        imp->setCharset(valueToStringWithNullCheck(exec, value));
        break;
    }
    case HrefAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        imp->setHref(valueToStringWithNullCheck(exec, value));
        break;
    }
    case HreflangAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        imp->setHreflang(valueToStringWithNullCheck(exec, value));
        break;
    }
    case MediaAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        imp->setMedia(valueToStringWithNullCheck(exec, value));
        break;
    }
    case RelAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        imp->setRel(valueToStringWithNullCheck(exec, value));
        break;
    }
    case RevAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        imp->setRev(valueToStringWithNullCheck(exec, value));
        break;
    }
    case TargetAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        imp->setTarget(valueToStringWithNullCheck(exec, value));
        break;
    }
    case TypeAttrNum: {
        HTMLLinkElement* imp = static_cast<HTMLLinkElement*>(impl());
        imp->setType(valueToStringWithNullCheck(exec, value));
        break;
    }
    }
}

JSValue* JSHTMLLinkElement::getConstructor(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier constructorIdentifier(exec, "[[HTMLLinkElement.constructor]]");
    return KJS::cacheGlobalObject<JSHTMLLinkElementConstructor>(exec, constructorIdentifier);
}


}
