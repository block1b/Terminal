/*++
Copyright (c) Microsoft Corporation

Module Name:
- CharRowCell.hpp

Abstract:
- data structure for one cell of a char row

Author(s):
- Austin Diviness (AustDi) 02-May-2018
--*/

#pragma once

#include "DbcsAttribute.hpp"

class CharRowCell final
{
public:
    CharRowCell();
    CharRowCell(const wchar_t wch, const DbcsAttribute attr);

    void EraseChars();
    void Reset();

    bool IsSpace() const noexcept;

    DbcsAttribute& DbcsAttr();
    const DbcsAttribute& DbcsAttr() const;

    wchar_t& Char();
    const wchar_t& Char() const;

    friend constexpr bool operator==(const CharRowCell& a, const CharRowCell& b) noexcept;
private:
    wchar_t _wch;
    DbcsAttribute _attr;

};

constexpr bool operator==(const CharRowCell& a, const CharRowCell& b) noexcept
{
    return (a._wch == b._wch &&
            a._attr == b._attr);
}
