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

#include "JSFile.h"

#include <wtf/GetPtr.h>

#include "File.h"
#include "KURL.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSFileTableValues[4] =
{
    { "fileName", (intptr_t)JSFile::FileNameAttrNum, DontDelete|ReadOnly, 0 },
    { "fileSize", (intptr_t)JSFile::FileSizeAttrNum, DontDelete|ReadOnly, 0 },
    { "constructor", (intptr_t)JSFile::ConstructorAttrNum, DontEnum, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSFileTable = { 7, JSFileTableValues, 0 };

/* Hash table for constructor */

static const HashTableValue JSFileConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSFileConstructorTable = { 0, JSFileConstructorTableValues, 0 };

class JSFileConstructor : public DOMObject {
public:
    JSFileConstructor(ExecState* exec)
        : DOMObject(exec->lexicalGlobalObject()->objectPrototype())
    {
        putDirect(exec->propertyNames().prototype, JSFilePrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSFileConstructor::s_info = { "FileConstructor", 0, &JSFileConstructorTable, 0 };

bool JSFileConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSFileConstructor, DOMObject>(exec, &JSFileConstructorTable, this, propertyName, slot);
}

JSValue* JSFileConstructor::getValueProperty(ExecState* exec, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(exec, token);
}

/* Hash table for prototype */

static const HashTableValue JSFilePrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSFilePrototypeTable = { 0, JSFilePrototypeTableValues, 0 };

const ClassInfo JSFilePrototype::s_info = { "FilePrototype", 0, &JSFilePrototypeTable, 0 };

JSObject* JSFilePrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSFile.prototype]]");
    return KJS::cacheGlobalObject<JSFilePrototype>(exec, prototypeIdentifier);
}

const ClassInfo JSFile::s_info = { "File", 0, &JSFileTable , 0 };

JSFile::JSFile(JSObject* prototype, File* impl)
    : DOMObject(prototype)
    , m_impl(impl)
{
}

JSFile::~JSFile()
{
    ScriptInterpreter::forgetDOMObject(m_impl.get());

}

bool JSFile::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSFile, Base>(exec, &JSFileTable, this, propertyName, slot);
}

JSValue* JSFile::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case FileNameAttrNum: {
        File* imp = static_cast<File*>(impl());
        return jsString(exec, imp->fileName());
    }
    case FileSizeAttrNum: {
        File* imp = static_cast<File*>(impl());
        return jsNumber(exec, imp->fileSize());
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

JSValue* JSFile::getConstructor(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier constructorIdentifier(exec, "[[File.constructor]]");
    return KJS::cacheGlobalObject<JSFileConstructor>(exec, constructorIdentifier);
}

KJS::JSValue* toJS(KJS::ExecState* exec, File* obj)
{
    return cacheDOMObject<File, JSFile, JSFilePrototype>(exec, obj);
}
File* toFile(KJS::JSValue* val)
{
    return val->isObject(&JSFile::s_info) ? static_cast<JSFile*>(val)->impl() : 0;
}

}
