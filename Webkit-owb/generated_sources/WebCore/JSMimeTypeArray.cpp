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

#include "JSMimeTypeArray.h"

#include <wtf/GetPtr.h>

#include <kjs/PropertyNameArray.h>
#include "AtomicString.h"
#include "MimeTypeArray.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSMimeTypeArrayTableValues[2] =
{
    { "length", (intptr_t)JSMimeTypeArray::LengthAttrNum, DontDelete|ReadOnly, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSMimeTypeArrayTable = { 0, JSMimeTypeArrayTableValues, 0 };

/* Hash table for prototype */

static const HashTableValue JSMimeTypeArrayPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSMimeTypeArrayPrototypeTable = { 0, JSMimeTypeArrayPrototypeTableValues, 0 };

const ClassInfo JSMimeTypeArrayPrototype::s_info = { "MimeTypeArrayPrototype", 0, &JSMimeTypeArrayPrototypeTable, 0 };

JSObject* JSMimeTypeArrayPrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSMimeTypeArray.prototype]]");
    return KJS::cacheGlobalObject<JSMimeTypeArrayPrototype>(exec, prototypeIdentifier);
}

const ClassInfo JSMimeTypeArray::s_info = { "MimeTypeArray", 0, &JSMimeTypeArrayTable , 0 };

JSMimeTypeArray::JSMimeTypeArray(JSObject* prototype, MimeTypeArray* impl)
    : DOMObject(prototype)
    , m_impl(impl)
{
}

JSMimeTypeArray::~JSMimeTypeArray()
{
    ScriptInterpreter::forgetDOMObject(m_impl.get());

}

bool JSMimeTypeArray::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    const HashEntry* entry = JSMimeTypeArrayTable.entry(exec, propertyName);
    if (entry) {
        slot.setStaticEntry(this, entry, staticValueGetter<JSMimeTypeArray>);
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<MimeTypeArray*>(impl())->length()) {
        slot.setCustomIndex(this, index, indexGetter);
        return true;
    }
    if (canGetItemsForName(exec, static_cast<MimeTypeArray*>(impl()), propertyName)) {
        slot.setCustom(this, nameGetter);
        return true;
    }
    return getStaticValueSlot<JSMimeTypeArray, Base>(exec, &JSMimeTypeArrayTable, this, propertyName, slot);
}

bool JSMimeTypeArray::getOwnPropertySlot(ExecState* exec, unsigned propertyName, PropertySlot& slot)
{
    if (propertyName < static_cast<MimeTypeArray*>(impl())->length()) {
        slot.setCustomIndex(this, propertyName, indexGetter);
        return true;
    }
    return getOwnPropertySlot(exec, Identifier::from(exec, propertyName), slot);
}

JSValue* JSMimeTypeArray::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case LengthAttrNum: {
        MimeTypeArray* imp = static_cast<MimeTypeArray*>(impl());
        return jsNumber(exec, imp->length());
    }
    }
    return 0;
}

void JSMimeTypeArray::getPropertyNames(ExecState* exec, PropertyNameArray& propertyNames)
{
    for (unsigned i = 0; i < static_cast<MimeTypeArray*>(impl())->length(); ++i)
        propertyNames.add(Identifier::from(exec, i));
     Base::getPropertyNames(exec, propertyNames);
}


JSValue* JSMimeTypeArray::indexGetter(ExecState* exec, const Identifier& propertyName, const PropertySlot& slot)
{
    JSMimeTypeArray* thisObj = static_cast<JSMimeTypeArray*>(slot.slotBase());
    return toJS(exec, static_cast<MimeTypeArray*>(thisObj->impl())->item(slot.index()));
}
KJS::JSValue* toJS(KJS::ExecState* exec, MimeTypeArray* obj)
{
    return cacheDOMObject<MimeTypeArray, JSMimeTypeArray, JSMimeTypeArrayPrototype>(exec, obj);
}
MimeTypeArray* toMimeTypeArray(KJS::JSValue* val)
{
    return val->isObject(&JSMimeTypeArray::s_info) ? static_cast<JSMimeTypeArray*>(val)->impl() : 0;
}

}
