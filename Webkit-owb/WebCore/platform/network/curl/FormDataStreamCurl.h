/*
 * Copyright (C) 2008 Apple Computer, Inc.  All rights reserved.
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

#ifndef FormatDataStreamCurl_h
#define FormatDataStreamCurl_h

#include <wtf/FastAllocBase.h>
#include "config.h"

#include "FileSystem.h"
#include "ResourceHandle.h"
#include <stdio.h>

namespace WebCore {

class FormDataStream/*: public WTF::FastAllocBase*/ {
public:
    FormDataStream(ResourceHandle* handle)
        : m_resourceHandle(handle)
        , m_file(0)
        , m_formDataElementIndex(0)
        , m_formDataElementDataOffset(0)
    {
    }

    ~FormDataStream();

    size_t read(void* ptr, size_t blockSize, size_t numberOfBlocks);

private:
    // We can hold a weak reference to our ResourceHandle as it holds a strong reference
    // to us through its ResourceHandleInternal.
    ResourceHandle* m_resourceHandle;

    FILE* m_file;
    size_t m_formDataElementIndex;
    size_t m_formDataElementDataOffset;
};

} // namespace WebCore

#endif // FormDataStreamCurl_h
