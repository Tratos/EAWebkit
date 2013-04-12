/*
 * THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 *
 * Copyright (C) 2005 Apple Computer, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

/*
* This file was modified by Electronic Arts Inc Copyright � 2009-2010
*/


#include "config.h"
#ifdef AVOID_STATIC_CONSTRUCTORS
#define DOM_XMLNAMES_HIDE_GLOBALS 1
#else
#define QNAME_DEFAULT_CONSTRUCTOR 1
#endif

#include "XMLNames.h"

namespace WebCore { 

XMLNames* XMLNames::mpInstance = NULL;

XMLNames::XMLNames() :
    xmlNamespaceURI("http://www.w3.org/XML/1998/namespace"),
    baseAttr(nullAtom, "base", xmlNamespaceURI),
    langAttr(nullAtom, "lang", xmlNamespaceURI),
    spaceAttr(nullAtom, "space", xmlNamespaceURI)
{

}

XMLNames::~XMLNames()
{
}

void XMLNames::init()
{
    AtomicString::init();
    if(mpInstance == NULL)
        mpInstance = new XMLNames;
}

void XMLNames::unInit()
{
    delete mpInstance;
    mpInstance = NULL;

}

XMLNames* XMLNames::Instance()
{
    return mpInstance;
}


WebCore::QualifiedName** XMLNames::getXMLAttr(size_t* size)
{
    static WebCore::QualifiedName* XMLAttr[] = {
        &baseAttr, &langAttr, &spaceAttr  };
    *size = 3;
    return XMLAttr;
}

} //namespace WebCore

