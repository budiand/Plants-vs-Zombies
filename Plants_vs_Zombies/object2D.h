#pragma once

#include <string>
#include <chrono>
#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateDiamond(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateSquare(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateHexagon(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color_outer, glm::vec3 color_inner, bool fill = false);
    Mesh* CreateStar(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    int generateRandomXCoordinate(int resolutionX);
    int generateRandomYCoordinate(int resolutionY);
    std::chrono::milliseconds generateRandomTimeInterval();
    //Mesh* CombineMeshes(const std::string& name, Mesh* mesh1, Mesh* mesh2);
}
