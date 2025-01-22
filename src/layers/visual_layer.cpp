#include "visual_layer.hpp"

#include "node/node.hpp"

#include <raylib/src/raylib.h>

namespace moirai
{
    void cVisualLayer::draw(sDrawData* draw_data)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("[LIGHTSAYS ^. .^] WELP, I'M A WINDOW NOW", 190, 200, 20, LIGHTGRAY);

        SetTextLineSpacing(LINE_SPACING);

        for (int32_t i {0}; i < draw_data->node_count; i++)
        {
            sNode* node {&draw_data->node_array[i]};
            DrawRectangle(node->pos_x, node->pos_y, node->size_x, node->size_y, node->get_color());
            DrawText(node->title, node->pos_x + NODE_HORIZONTAL_MARGIN, node->pos_y + NODE_VERTICAL_MARGIN, NODE_TEXT_SIZE, BLACK);

            int32_t parent_index {draw_data->parents_array[i]};
            if (parent_index != -1)
            {
                sNode* parent_node {&draw_data->node_array[parent_index]};
                DrawLine(node->pos_x + node->size_x / 2, node->pos_y, parent_node->pos_x + parent_node->size_x / 2, parent_node->pos_y + parent_node->size_y, BLACK);
            }
        }

        EndDrawing();
    }
}
