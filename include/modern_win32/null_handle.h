//
// Copyright � 2020 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 

#ifndef __UTIL_SYSTEM_WINDOWS_NULL_HANDLE_H__
#define __UTIL_SYSTEM_WINDOWS_NULL_HANDLE_H__

#include <modern_win32/unique_handle.h>

#ifdef _WIN32

#include <Windows.h>

namespace modern_win32
{
    struct null_handle_traits
    {
        using native_handle_type = HANDLE;

        static constexpr native_handle_type invalid() noexcept
        {
			return nullptr;
        }
        static void close(native_handle_type const handle) noexcept
        {
            CloseHandle(handle);
        }
    };

    using null_handle = unique_handle<null_handle_traits>;

}

#endif

#endif