#include "precomp.h"
#include "Terminal.hpp"
using namespace Microsoft::Terminal::Core;
using namespace Microsoft::Console::Types;

const Viewport& Terminal::GetViewport()
{
    return _visibleViewport;
}

const TextBuffer& Terminal::GetTextBuffer()
{
    return *_buffer;
}

const FontInfo* Terminal::GetFontInfo()
{
    THROW_HR(E_NOTIMPL);

}

const TextAttribute Terminal::GetDefaultBrushColors()
{
    return TextAttribute{};
}

const void Terminal::GetColorTable(COLORREF** const /*ppColorTable*/,
                                   size_t* const /*pcColors*/)
{
    THROW_HR(E_NOTIMPL);
}

const COLORREF Terminal::GetForegroundColor(const TextAttribute& /*attr*/) const
{
    return RGB(255, 255, 255);
}

const COLORREF Terminal::GetBackgroundColor(const TextAttribute& /*attr*/) const
{
    return RGB(0, 0, 0);
}

COORD Terminal::GetCursorPosition() const
{
    const auto& cursor = _buffer->GetCursor();
    return cursor.GetPosition();
}

bool Terminal::IsCursorVisible() const
{
    const auto& cursor = _buffer->GetCursor();
    return cursor.IsVisible() && cursor.IsOn() && !cursor.IsPopupShown();
}

ULONG Terminal::GetCursorHeight() const
{
    return _buffer->GetCursor().GetSize();
}

CursorType Terminal::GetCursorStyle() const
{
    return _buffer->GetCursor().GetType();
}

COLORREF Terminal::GetCursorColor() const
{
    return INVALID_COLOR;
}

bool Terminal::IsCursorDoubleWidth() const
{
    return false;
}

const ConsoleImeInfo* Terminal::GetImeData()
{
    THROW_HR(E_NOTIMPL);
}

const TextBuffer& Terminal::GetImeCompositionStringBuffer(size_t /*iIndex*/)
{
    THROW_HR(E_NOTIMPL);
}

const bool Terminal::IsGridLineDrawingAllowed()
{
    return true;
}

std::vector<SMALL_RECT> Terminal::GetSelectionRects()
{
    return {};
}

const std::wstring Terminal::GetConsoleTitle() const
{
    return _title;
}


void Terminal::LockConsole()
{
}

void Terminal::UnlockConsole()
{
}
