/* /////////////////////////////////////////////////////////////////////////
 * File:    winstl/window/menu_functions.h (originally MWMenu.h, ::SynesisWin)
 *
 * Purpose: Menu functions.
 *
 * Created: 20th October 1994
 * Updated: 24th December 2024
 *
 * Home:    http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1994-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file winstl/window/menu_functions.h
 *
 * \brief [C, C++] Menu functions
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_H_MENU_FUNCTIONS
#define WINSTL_INCL_WINSTL_WINDOW_H_MENU_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_H_MENU_FUNCTIONS_MAJOR    3
# define WINSTL_VER_WINSTL_WINDOW_H_MENU_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_WINDOW_H_MENU_FUNCTIONS_REVISION 4
# define WINSTL_VER_WINSTL_WINDOW_H_MENU_FUNCTIONS_EDIT     138
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

STLSOFT_INLINE
BOOL
winstl__IsMenuItemChecked(
    HMENU   hmenu
,   WORD    wID
)
{
    MENUITEMINFO    mii;

    mii.cbSize  =   sizeof(mii);
    mii.fMask   =   MIIM_STATE;

    if (STLSOFT_NS_GLOBAL(GetMenuItemInfo)(hmenu, wID, FALSE, &mii))
    {
        if (MFS_CHECKED == (MFS_CHECKED & mii.fState))
        {
            return TRUE;
        }
    }

    return FALSE;
}

STLSOFT_INLINE
BOOL
winstl__SetMenuItemStateByIndex(
    HMENU   hmenu
,   int     i
,   UINT    state
)
{
    MENUITEMINFO    mii;

    mii.cbSize  =   sizeof(mii);
    mii.fMask   =   MIIM_STATE;
    mii.fState  =   state;

    return STLSOFT_NS_GLOBAL(SetMenuItemInfo)(hmenu, stlsoft_static_cast(UINT, i), TRUE, &mii);
}

STLSOFT_INLINE
BOOL
winstl__SetMenuItemStateById(
    HMENU   hmenu
,   UINT    id
,   UINT    state
)
{
    MENUITEMINFO    mii;

    mii.cbSize  =   sizeof(mii);
    mii.fMask   =   MIIM_STATE;
    mii.fState  =   state;

    return STLSOFT_NS_GLOBAL(SetMenuItemInfo)(hmenu, id, FALSE, &mii);
}


/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

inline
BOOL
IsMenuItemChecked(
    HMENU   hmenu
,   WORD    wID
)
{
    return winstl__IsMenuItemChecked(hmenu, wID);
}

inline
BOOL
SetMenuItemStateByIndex(
    HMENU   hmenu
,   int     i
,   UINT    state
)
{
    return winstl__SetMenuItemStateByIndex(hmenu, i, state);
}

inline
BOOL
SetMenuItemStateById(
    HMENU   hmenu
,   UINT    id
,   UINT    state
)
{
    return winstl__SetMenuItemStateById(hmenu, id, state);
}
#endif /* __cplusplus */


/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_WINDOW_H_MENU_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

