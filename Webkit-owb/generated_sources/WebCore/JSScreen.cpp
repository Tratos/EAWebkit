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

#include "JSScreen.h"

#include <wtf/GetPtr.h>

#include "Screen.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSScreenTableValues[9] =
{
    { "height", (intptr_t)JSScreen::HeightAttrNum, DontDelete|ReadOnly, 0 },
    { "width", (intptr_t)JSScreen::WidthAttrNum, DontDelete|ReadOnly, 0 },
    { "colorDepth", (intptr_t)JSScreen::ColorDepthAttrNum, DontDelete|ReadOnly, 0 },
    { "pixelDepth", (intptr_t)JSScreen::PixelDepthAttrNum, DontDelete|ReadOnly, 0 },
    { "availLeft", (intptr_t)JSScreen::AvailLeftAttrNum, DontDelete|ReadOnly, 0 },
    { "availTop", (intptr_t)JSScreen::AvailTopAttrNum, DontDelete|ReadOnly, 0 },
    { "availHeight", (intptr_t)JSScreen::AvailHeightAttrNum, DontDelete|ReadOnly, 0 },
    { "availWidth", (intptr_t)JSScreen::AvailWidthAttrNum, DontDelete|ReadOnly, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSScreenTable = { 63, JSScreenTableValues, 0 };

/* Hash table for prototype */

static const HashTableValue JSScreenPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSScreenPrototypeTable = { 0, JSScreenPrototypeTableValues, 0 };

const ClassInfo JSScreenPrototype::s_info = { "ScreenPrototype", 0, &JSScreenPrototypeTable, 0 };

JSObject* JSScreenPrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSScreen.prototype]]");
    return KJS::cacheGlobalObject<JSScreenPrototype>(exec, prototypeIdentifier);
}

const ClassInfo JSScreen::s_info = { "Screen", 0, &JSScreenTable , 0 };

JSScreen::JSScreen(JSObject* prototype, Screen* impl)
    : DOMObject(prototype)
    , m_impl(impl)
{
}

JSScreen::~JSScreen()
{
    ScriptInterpreter::forgetDOMObject(m_impl.get());

}

bool JSScreen::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSScreen, Base>(exec, &JSScreenTable, this, propertyName, slot);
}

JSValue* JSScreen::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case HeightAttrNum: {
        Screen* imp = static_cast<Screen*>(impl());
        return jsNumber(exec, imp->height());
    }
    case WidthAttrNum: {
        Screen* imp = static_cast<Screen*>(impl());
        return jsNumber(exec, imp->width());
    }
    case ColorDepthAttrNum: {
        Screen* imp = static_cast<Screen*>(impl());
        return jsNumber(exec, imp->colorDepth());
    }
    case PixelDepthAttrNum: {
        Screen* imp = static_cast<Screen*>(impl());
        return jsNumber(exec, imp->pixelDepth());
    }
    case AvailLeftAttrNum: {
        Screen* imp = static_cast<Screen*>(impl());
        return jsNumber(exec, imp->availLeft());
    }
    case AvailTopAttrNum: {
        Screen* imp = static_cast<Screen*>(impl());
        return jsNumber(exec, imp->availTop());
    }
    case AvailHeightAttrNum: {
        Screen* imp = static_cast<Screen*>(impl());
        return jsNumber(exec, imp->availHeight());
    }
    case AvailWidthAttrNum: {
        Screen* imp = static_cast<Screen*>(impl());
        return jsNumber(exec, imp->availWidth());
    }
    }
    return 0;
}

KJS::JSValue* toJS(KJS::ExecState* exec, Screen* obj)
{
    return cacheDOMObject<Screen, JSScreen, JSScreenPrototype>(exec, obj);
}
Screen* toScreen(KJS::JSValue* val)
{
    return val->isObject(&JSScreen::s_info) ? static_cast<JSScreen*>(val)->impl() : 0;
}

}
