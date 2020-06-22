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

#ifndef __MODERN_WIN32_SHARED_WINDOWS_EXCEPTION_H__
#define __MODERN_WIN32_SHARED_WINDOWS_EXCEPTION_H__

#if _WIN32

#include <system_error>
#include <Windows.h>

namespace modern_win32
{
    /// <summary>
    /// wrapper around system_error which constructs error value from GetLastError result
    /// </summary>
    class windows_exception final : public std::system_error
    {
    public:
        explicit windows_exception(char const* message) 
            : std::system_error(GetLastError(), std::system_category(), message)
        {
        }
        explicit windows_exception() 
            : std::system_error(GetLastError(), std::system_category())
        {
        }
    };

}

#endif
#endif
