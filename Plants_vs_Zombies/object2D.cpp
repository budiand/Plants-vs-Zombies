#include "object2D.h"
#include <vector>
#include <random>
#include <chrono>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(length, length, 0), color), //0
        VertexFormat(corner + glm::vec3(-length, length, 0), color), //1
        VertexFormat(corner + glm::vec3(-length, -length, 0), color), //2
        VertexFormat(corner + glm::vec3(length, -length, 0), color) //3
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3};

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {

        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(-length / 10, -length, 0), color), //0
        VertexFormat(corner + glm::vec3(length / 10, -length, 0), color), //1
        VertexFormat(corner + glm::vec3(length / 10, length, 0), color), //2
        VertexFormat(corner + glm::vec3(-length / 10, length, 0), color) //3
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* object2D::CreateDiamond(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(-length / 2, 0, 0), color), //0
        VertexFormat(corner + glm::vec3(0, -length, 0), color), //1
        VertexFormat(corner + glm::vec3(length / 2, 0, 0), color), //2
        VertexFormat(corner + glm::vec3(0, length, 0), color), //3
        
        // tureta

        VertexFormat(corner + glm::vec3(0, -length / 4, 0), color), //4
        VertexFormat(corner + glm::vec3(length, -length / 4, 0), color), //5
        VertexFormat(corner + glm::vec3(length, length / 4, 0), color), //6
        VertexFormat(corner + glm::vec3(0, length / 4, 0), color) //7
    };

    Mesh* diamond = new Mesh(name);
    std::vector<unsigned int> indices = { 
                                            0, 1, 2,
                                            0, 2, 3,
                                            4, 5, 6,
                                            4, 6, 7};

    if (!fill) {
        diamond->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        indices.push_back(0);
        indices.push_back(2);

        indices.push_back(4);
        indices.push_back(6);
    }

    diamond->InitFromData(vertices, indices);
    return diamond;
}

Mesh* object2D::CreateHexagon(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color_outer,
    glm::vec3 color_inner,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices;

    for (int i = 0; i < 6; i++) {
        float angle = glm::radians(60.0f * i); // 60 de grade are fiecare capat de triunghi
        vertices.push_back(VertexFormat(corner + glm::vec3(length * cos(angle), length * sin(angle), 0.0f), color_outer));
    }
    for (int i = 6; i < 12; i++) {
        float angle = glm::radians(60.0f * i);
        vertices.push_back(VertexFormat(corner + glm::vec3(length / 2 * 1.4f * cos(angle), length / 2 * 1.4f * sin(angle), 0.5f), color_inner));
    }

    std::vector<unsigned int> indices = {
            0, 1, 2,
           1, 2, 3,
           2, 3, 4,
           3, 4, 5,
           4, 5, 0,
           6,7,8,
           7,8,9,
           8,9,10,
           9,10,11,
           10,11,6
    };

    Mesh* hexagon = new Mesh(name);

    if (!fill) {
        hexagon->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        indices.push_back(0);
        for (int i = 0; i < 12; ++i) {
            if (i % 2 == 0 && i!=11) {
                indices.push_back(i + 2); //0,2,4,6,8,10,12
            }
        }
    }
    
    hexagon->InitFromData(vertices, indices);
    return hexagon;
}


Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices;
    
    for (int i = 0; i < 5; i++) {
        float angle = glm::radians(72.0f * i); // 72 de grade are fiecare capat de triunghi
        vertices.push_back(VertexFormat(corner + glm::vec3(length * cos(angle), length * sin(angle), 0.0f), color));
    }

    for (int i = 0; i < 5; i++) {
        float angle = glm::radians(36.0f + 72.0f * i); // 72 + 36 de grade are fiecare capat de triunghi
        vertices.push_back(VertexFormat(corner + glm::vec3(length / 2  * cos(angle), length / 2  * sin(angle), 0.0f), color));
    }
    

    std::vector<unsigned int> indices = {
        8,9,5,
        9,5,6,
        5,6,7,
        6,7,8,
        7,8,9,
        
        5,1,6,
        6,2,7,
        7,3,8,
        8,4,9,
        9,0,5
        
    };

    Mesh* star = new Mesh(name);

    if (!fill) {
        star->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        
        indices.push_back(5);
        indices.push_back(7);
        indices.push_back(9);
    }

    star->InitFromData(vertices, indices);
    return star;
}