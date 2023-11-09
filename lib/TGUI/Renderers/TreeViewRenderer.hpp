/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2023 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_TREE_VIEW_RENDERER_HPP
#define TGUI_TREE_VIEW_RENDERER_HPP


#include <TGUI/Renderers/WidgetRenderer.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TGUI_MODULE_EXPORT namespace tgui
{
    class TGUI_API TreeViewRenderer : public WidgetRenderer
    {
    public:

        using WidgetRenderer::WidgetRenderer;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the borders
        /// @param borders  Size of the borders
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorders(const Borders& borders);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the borders
        /// @return border size
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Borders getBorders() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the padding of the tree view
        /// @param padding  The padding width and height
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setPadding(const Padding& padding);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the padding
        /// @return padding size
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Padding getPadding() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color of the tree view
        /// @param color  The new background color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColor(Color color);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color
        /// @return Background color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBackgroundColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the borders
        /// @param color  The new border color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColor(Color color);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the borders
        /// @return Border color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBorderColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text
        /// @param color  The new text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColor(Color color);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the text
        /// @return Text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getTextColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text of the item below the mouse
        /// @param color  The new hover text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColorHover(Color color);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the text of the item below the mouse
        /// @return Hover text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getTextColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text from the selected item
        /// @param color  The new selected text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSelectedTextColor(Color color);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the text from the selected item
        /// @return Selected text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getSelectedTextColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text of the selected item when it is below the mouse
        /// @param color  The new hover text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSelectedTextColorHover(Color color);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the text of the selected item when it is below the mouse
        /// @return Hover text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getSelectedTextColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color of the selected item
        /// @param color  The new selected item background color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSelectedBackgroundColor(Color color);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color of the selected item
        /// @return Selected item background color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getSelectedBackgroundColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color used for the item below the mouse
        /// @param color  The new hover background color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColorHover(Color color);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color used for the item below the mouse
        /// @return Background color of hovered item
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getBackgroundColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color used for the selected item when the mouse hovers over it
        /// @param backgroundColor  The new selected hover background color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSelectedBackgroundColorHover(Color backgroundColor);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color used for the selected item when the mouse hovers over it
        /// @return Background color of selected item in hover state
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Color getSelectedBackgroundColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the renderer data of the scrollbar
        /// @param scrollbarRendererData  Data about how the scrollbar should look
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setScrollbar(std::shared_ptr<RendererData> scrollbarRendererData);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer data of the scrollbar
        /// @return Data about how the scrollbar looks
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD std::shared_ptr<RendererData> getScrollbar() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the wanted width of the scrollbar
        /// @param scrollbarWidth  Requested scrollbar width or 0 to use the default width (texture size if using textures)
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setScrollbarWidth(float scrollbarWidth);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the wanted width of the scrollbar
        /// @return Requested scrollbar width or 0 if no width was set (texture width or default value will be used)
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD float getScrollbarWidth() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background image of the tree view
        ///
        /// @param texture  The background texture
        ///
        /// When this image is set, the background color property will be ignored.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureBackground(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background image of the tree view
        ///
        /// @return Background texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureBackground() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image used in front of an expanded item
        ///
        /// @param textureBranchExpanded  The expanded branch texture
        ///
        /// When this texture is not set, the TextureBranchCollapsed will be used when available.
        /// If neither of these textures are set, TextureLeaf is tried.
        /// If TextureLeaf isn't set either then a "-" symbol will be displayed in the same color as the text.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureBranchExpanded(const Texture& textureBranchExpanded);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image used in front of an expanded item
        /// @return The expanded branch texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureBranchExpanded() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image used in front of a collapsed item
        ///
        /// @param textureBranchCollapsed  The collapsed branch texture
        ///
        /// When this texture is not set, the TextureBranchExpanded will be used when available.
        /// If neither of these textures are set, TextureLeaf is tried.
        /// If TextureLeaf isn't set either then a "+" symbol will be displayed in the same color as the text.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureBranchCollapsed(const Texture& textureBranchCollapsed);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image used in front of a collapsed item
        /// @return The collapsed branch texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureBranchCollapsed() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image used in front of a lead item
        ///
        /// @param textureLeaf  The lead item texture
        ///
        /// When neither TextureBranchExpanded and TextureBranchCollapsed are set, this texture is also used for branch nodes.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureLeaf(const Texture& textureLeaf);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image used in front of a leaf item
        /// @return The lead item texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const Texture& getTextureLeaf() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_TREE_VIEW_RENDERER_HPP
