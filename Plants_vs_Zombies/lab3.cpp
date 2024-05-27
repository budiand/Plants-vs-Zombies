#include "lab_m1/lab3/lab3.h"

#include <vector>
#include <iostream>
#include <string>
#include <random>


#include "lab_m1/lab3/transform2D.h"
#include "lab_m1/lab3/object2D.h"

using namespace std;
using namespace m1;

Lab3::Lab3()
{
}


Lab3::~Lab3()
{
}


void Lab3::Init()
{
    resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    resolution = window->GetResolution();

    float squareSide = 50;
    float rectangle_L = 200;
   
    // Initialize angularStep
    angularStep = 0;

    // initialize life
    lives = 3;

    // initialize hexagon attributes
    rh = 0;
    random_time = dist_time(gen);

    // initialize diamond attributes
    x_diamond = -200;
    y_diamond = -200;
    nume = "diamond1";
    
    rd = 0;
    scroll = false;
    for (int i = 0; i < 9; i++) {
        obiecte[i].x = -50;
        obiecte[i].y = -50;
        obiecte[i].exists = false;
        obiecte[i].descend = false;
        obiecte[i].sx_diamond = 1;
        obiecte[i].sy_diamond = 1;
    }
    unu = doi = trei = patru = false;

    // initialize star attributes
    rs = 0;
    star_counter = 1.0f;
    money = 5;
  

    //initializare dreptunghi
    Mesh* rectangle = object2D::CreateRectangle("rectangle1", corner, rectangle_L, glm::vec3(137.0f / 255.0f, 2.0f / 255.0f, 62.0f / 255.0f), true);
    AddMeshToList(rectangle);

    //initializare patrat verde
    Mesh* square1 = object2D::CreateSquare("square1", corner, squareSide, glm::vec3(80.0f / 255.0f, 114.0f / 255.0f, 85.0f / 255.0f), true);
    AddMeshToList(square1);

    // initializare patrat incadrator
    Mesh* square2 = object2D::CreateSquare("square2", corner, squareSide, glm::vec3(137.0f / 255.0f, 2.0f / 255.0f, 62.0f / 255.0f));
    AddMeshToList(square2);

    // initializare patrat viata
    Mesh* square3 = object2D::CreateSquare("square3", corner, squareSide, glm::vec3(195.0f / 255.0f, 66.0f / 255.0f, 63.0f / 255.0f), true);
    AddMeshToList(square3);

    // initializare romburi
    Mesh* diamond1 = object2D::CreateDiamond("diamond1", corner, squareSide, glm::vec3(250.0f / 255.0f, 240.0f / 255.0f, 202.0f / 255.0f), true);
    AddMeshToList(diamond1);

    Mesh* diamond2 = object2D::CreateDiamond("diamond2", corner, squareSide, glm::vec3(242.0f / 255.0f, 100.0f / 255.0f, 25.0f / 255.0f), true);
    AddMeshToList(diamond2);

    Mesh* diamond3 = object2D::CreateDiamond("diamond3", corner, squareSide, glm::vec3(85.0f / 255.0f, 221.0f / 255.0f, 224.0f / 255.0f), true);
    AddMeshToList(diamond3);

    Mesh* diamond4 = object2D::CreateDiamond("diamond4", corner, squareSide, glm::vec3(165.0f / 255.0f, 102.0f / 255.0f, 139.0f / 255.0f), true);
    AddMeshToList(diamond4);

    //initializare hexagoane
    Mesh* hexagon1 = object2D::CreateHexagon("hexagon1", corner, squareSide, glm::vec3(250.0f / 255.0f, 240.0f / 255.0f, 202.0f / 255.0f), glm::vec3(136.0f / 255.0f, 160.0f / 255.0f, 150.0f / 255.0f), true);
    AddMeshToList(hexagon1);

    Mesh* hexagon2 = object2D::CreateHexagon("hexagon2", corner, squareSide, glm::vec3(242.0f / 255.0f, 100.0f / 255.0f, 25.0f / 255.0f), glm::vec3(136.0f / 255.0f, 160.0f / 255.0f, 150.0f / 255.0f), true);
    AddMeshToList(hexagon2);

    Mesh* hexagon3 = object2D::CreateHexagon("hexagon3", corner, squareSide, glm::vec3(85.0f / 255.0f, 221.0f / 255.0f, 224.0f / 255.0f), glm::vec3(136.0f / 255.0f, 160.0f / 255.0f, 150.0f / 255.0f), true);
    AddMeshToList(hexagon3);

    Mesh* hexagon4 = object2D::CreateHexagon("hexagon4", corner, squareSide, glm::vec3(165.0f / 255.0f, 102.0f / 255.0f, 139.0f / 255.0f), glm::vec3(136.0f / 255.0f, 160.0f / 255.0f, 150.0f / 255.0f), true);
    AddMeshToList(hexagon4);


    // initializare stars
    Mesh* star1 = object2D::CreateStar("star1", corner, squareSide, glm::vec3(250.0f / 255.0f, 240.0f / 255.0f, 202.0f / 255.0f), true);
    AddMeshToList(star1);

    Mesh* star2 = object2D::CreateStar("star2", corner, squareSide, glm::vec3(242.0f / 255.0f, 100.0f / 255.0f, 25.0f / 255.0f), true);
    AddMeshToList(star2);

    Mesh* star3 = object2D::CreateStar("star3", corner, squareSide, glm::vec3(85.0f / 255.0f, 221.0f / 255.0f, 224.0f / 255.0f), true);
    AddMeshToList(star3);

    Mesh* star4 = object2D::CreateStar("star4", corner, squareSide, glm::vec3(165.0f / 255.0f, 102.0f / 255.0f, 139.0f / 255.0f), true);
    AddMeshToList(star4);

    // stelute bani
    Mesh* gold_star = object2D::CreateStar("gold_star", corner, squareSide, glm::vec3(230.0f/255.0f, 158.0f/255.0f, 75.0f/255.0f), true);
    AddMeshToList(gold_star);

    // stelute colectabile
    Mesh* collect_star = object2D::CreateStar("collect_star", corner, squareSide, glm::vec3(244.0f / 255.0f, 211.0f / 255.0f, 94.0f / 255.0f), true);
    AddMeshToList(collect_star);
    time_to_shine = 2.0f;
}

void Lab3::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices)
{
    unsigned int VAO = 0;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO = 0;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    unsigned int IBO = 0;

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

    // Set vertex position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

    // Set vertex normal attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

    // Set texture coordinate attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

    // Set vertex color attribute
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
    // ========================================================================

    glBindVertexArray(0);


    // Check for OpenGL errors
    if (GetOpenGLError() == GL_INVALID_OPERATION)
    {
        cout << "\t[NOTE] : For students : DON'T PANIC! This error should go away when completing the tasks." << std::endl;
        cout << "\t[NOTE] : For developers : This happens because OpenGL core spec >=3.1 forbids null VAOs." << std::endl;
    }

    // Mesh information is saved into a Mesh object
    meshes[name] = new Mesh(name);
    meshes[name]->InitFromBuffer(VAO, static_cast<unsigned int>(indices.size()));
}


void Lab3::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Lab3::Update(float deltaTimeSeconds)
{
    glEnable(GL_CULL_FACE);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 50;
    

    // coliziune hexagon si romb
    rd = squareSide;
    rh = squareSide;

    for (auto& hexagon : inamici) {
        for (int i = 0; i < 9; i++) {
            if (hexagon.exists && obiecte[i].exists) {
                float distance = glm::distance(glm::vec2(hexagon.x, hexagon.y), glm::vec2(obiecte[i].x, obiecte[i].y));

                if (rd + rh > distance) 
                    obiecte[i].descend = true;
            }
        }
    }

    // disparitie hexagon la atingerea dreptunghiului rosu
    for (auto& hexagon : inamici) {
        if (hexagon.exists == true && hexagon.x <= 30) {
            hexagon.exists = false;
            lives--;
        }
    }
   

 
 // aparitie random hexagoane
    
    for (auto& hexagon : inamici) {
        if (hexagon.descend == true) {

            hexagon.sx_hexagon -= deltaTimeSeconds;
            hexagon.sy_hexagon -= deltaTimeSeconds;
            hexagon.x += 100 * deltaTimeSeconds;

            if (hexagon.sx_hexagon <= 0 && hexagon.sy_hexagon <= 0)
                hexagon.exists = false;
        }
        if (hexagon.exists) {
            hexagon.x -= 100* deltaTimeSeconds;

            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(hexagon.x, hexagon.y) * transform2D::Rotate(6.0f) * transform2D::Scale(hexagon.sx_hexagon, hexagon.sy_hexagon);
            RenderMesh2D(meshes[hexagon.name], shaders["VertexColor"], modelMatrix);
        }
    }

    random_time -= deltaTimeSeconds;
    if (random_time <= 0) {
 
        Hexagoane hexagon;
        index1 = dist_indices(gen);
        index2 = dist_names(gen);

        hexagon.x = resolution.x + squareSide;
        hexagon.y = lines[index1];
        hexagon.name = "hexagon" + std::to_string(index2);
        hexagon.exists = true;
        hexagon.descend = false;
        hexagon.sx_hexagon = 1;
        hexagon.sy_hexagon = 1;
        hexagon.lives = 3;
        random_time = dist_time(gen);
                
        inamici.push_back(hexagon);
    }


    // 9 romburi
    for (int i = 0; i < 9; i++) {
        if (obiecte[i].descend == true) {
            obiecte[i].sx_diamond -= 4 * deltaTimeSeconds;
            obiecte[i].sy_diamond -= 4 * deltaTimeSeconds;

            if (obiecte[i].sx_diamond <= 0 && obiecte[i].sy_diamond <= 0) {
                obiecte[i].exists = false;
            }
        }
        if (obiecte[i].exists == true) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(obiecte[i].x, obiecte[i].y) * transform2D::Scale(obiecte[i].sx_diamond, obiecte[i].sy_diamond);
            RenderMesh2D(meshes[obiecte[i].name], shaders["VertexColor"], modelMatrix);
        }
    }


     // aparitie stele in functie de existenta si de culoarea hexagonului
    for (auto& hexagon : inamici) {
        for (int i = 0; i < 9; i++) {
            if (hexagon.exists == true && obiecte[i].exists) {
                if (obiecte[i].y == hexagon.y && obiecte[i].name == ("diamond" + std::string(1, hexagon.name.back()))) {
                    star_counter -= deltaTimeSeconds;
                    if (star_counter <= 0) {

                        Stars star;
                        star.x = obiecte[i].x;
                        star.y = obiecte[i].y;
                        star.name = "star" + std::string(1, obiecte[i].name.back());
                        star.exists = true;
                        stars.push_back(star);
                        star_counter = 2.0f;
                    }
                }
            }
        }
    }

    // coliziune stea hexagon
    rs = squareSide;

    for (auto& hexagon : inamici) {
        for (auto& star : stars) {
            if (hexagon.exists && star.exists && star.name == ("star" + std::string(1, hexagon.name.back()))) {
                float distance = glm::distance(glm::vec2(hexagon.x, hexagon.y), glm::vec2(star.x, star.y));

                if (rs + rh > distance) {
                    hexagon.lives--;
                    star.exists = false;

                    if (hexagon.lives == 0)    
                        hexagon.descend = true;
                }
            }
        }
    }

    // deplasare si rotire proiectil
    angularStep += deltaTimeSeconds;

    for (auto& star : stars) {
        if (star.exists == true) {

            star.x += 250 * deltaTimeSeconds;
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(star.x, star.y) * transform2D::Scale(0.8, 0.8) * transform2D::Rotate(-angularStep * 6.0f);
            RenderMesh2D(meshes[star.name], shaders["VertexColor"], modelMatrix);
        }
    }


    // generare stelute colectabile
    time_to_shine -= deltaTimeSeconds;
    if (time_to_shine <= 0) {
        
        Collectables star1;
        star1.x = dist_starx(gen_star);
        star1.y = dist_stary(gen_star);
        star1.sx = 0.5f;
        star1.sy = 0.5f;
        star1.size = squareSide;
        star1.exists = true;
        collectables.push_back(star1);

        Collectables star2;
        star2.x = dist_starx(gen_star);
        star2.y = dist_stary(gen_star);
        star2.sx = 0.5f;
        star2.sy = 0.5f;
        star2.size = squareSide;
        star2.exists = true;
        collectables.push_back(star2);

        Collectables star3;
        star3.x = dist_starx(gen_star);
        star3.y = dist_stary(gen_star);
        star3.sx = 0.5f;
        star3.sy = 0.5f;
        star3.size = squareSide;
        star3.exists = true;
        collectables.push_back(star3);

        time_to_shine = dist_star_time(gen_star);
    }


    // randare stelute colectabile
    float angle = glm::radians(18.0f);
    for (auto& star : collectables) {

        if (star.exists) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(star.x, star.y) * transform2D::Scale(star.sx, star.sy) * transform2D::Rotate(angle);
            RenderMesh2D(meshes["collect_star"], shaders["VertexColor"], modelMatrix);
        }
    }

    // rombul invizibil care ma ajuta doar la drag and drop
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(x_diamond, y_diamond);
    RenderMesh2D(meshes[nume], shaders["VertexColor"], modelMatrix);

    // dreptunghi rosu
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(30, 220);
    RenderMesh2D(meshes["rectangle1"], shaders["VertexColor"], modelMatrix);

    // patrate verzi 
    for (int i = 0; i < 3; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(130 + i*130, 70);
        RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    }

    for (int i = 0; i < 3; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(130 + i*130, 220);
        RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    }

    for (int i = 0; i < 3; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(130 + i*130, 370);
        RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    }

    // punere patrate incadratoare in scena
    for (int i = 0; i < 4; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(100 + i*160, 650);
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
    }

    // romburi in patrate incadratoare
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(100, 650);
    RenderMesh2D(meshes["diamond1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(260, 650);
    RenderMesh2D(meshes["diamond2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(420, 650);
    RenderMesh2D(meshes["diamond3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(580, 650);
    RenderMesh2D(meshes["diamond4"], shaders["VertexColor"], modelMatrix);
    
    // stelute gold
    // primul romb
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(60, 580) * transform2D::Scale(0.3, 0.3) *transform2D::Rotate(angle);
    RenderMesh2D(meshes["gold_star"], shaders["VertexColor"], modelMatrix);

    // al doilea romb
    for (int i = 0; i < 2; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(220 + i*30, 580) * transform2D::Scale(0.3, 0.3) * transform2D::Rotate(angle);
        RenderMesh2D(meshes["gold_star"], shaders["VertexColor"], modelMatrix);
    }

    // al treilea romb
    for (int i = 0; i < 2; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(380 + i*30, 580) * transform2D::Scale(0.3, 0.3) * transform2D::Rotate(angle);
        RenderMesh2D(meshes["gold_star"], shaders["VertexColor"], modelMatrix);
    }

    // al patrulea romb
    for (int i = 0; i < 3; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(540 + i*30, 580) * transform2D::Scale(0.3, 0.3) * transform2D::Rotate(angle);
        RenderMesh2D(meshes["gold_star"], shaders["VertexColor"], modelMatrix);
    }

    for (int i = 0; i < money; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(700 + i * 30, 580) * transform2D::Scale(0.3, 0.3) * transform2D::Rotate(angle);
        RenderMesh2D(meshes["gold_star"], shaders["VertexColor"], modelMatrix);
    }

    // patratele de viata
    for (int i = 0; i < lives; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(740 + 160 * i, 650);// *transform2D::Scale(0.7, 0.7);
        RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);
    }

    if (lives == 0) 
        exit(0);

    glDisable(GL_CULL_FACE);
}

void Lab3::FrameEnd()
{
}


void Lab3::OnInputUpdate(float deltaTime, int mods)
{
}


void Lab3::OnKeyPress(int key, int mods)
{
    
}


void Lab3::OnKeyRelease(int key, int mods)
{
    
}


void Lab3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    if (scroll == true) {
        x_diamond = mouseX;
        y_diamond = 720 - mouseY;
    }
}


void Lab3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // colectare stelute colectabile
    for (auto& star : collectables) {
        if (button == GLFW_MOUSE_BUTTON_2 && mouseY >= 720 - star.y-star.size*star.sy
                                          && mouseY <= 720 - star.y + star.size* star.sy
                                          && mouseX >= star.x - star.size*star.sx
                                          && mouseX <= star.x + star.size * star.sx) {
            money++;
            star.exists = false;
        }
    }

    // stergere romburi la apasarea click dreapta
    for (int i = 0; i < 3; i++) {
        if (button == GLFW_MOUSE_BUTTON_3 && mouseY >= 600 && 700 >= mouseY && 180 + i*130 >= mouseX && mouseX >= 80 + i*130)  
            obiecte[i].descend = true;       
    }

    for (int i = 0; i < 3; i++) {
        if (button == GLFW_MOUSE_BUTTON_3 && mouseY >= 450 && 550 >= mouseY && 180 + i*130 >= mouseX && mouseX >= 80 + i*130)
            obiecte[i+3].descend = true;   
    }

    for (int i = 0; i < 3; i++) {
        if (button == GLFW_MOUSE_BUTTON_3 && mouseY >= 300 && 400 >= mouseY && 180 + i*130 >= mouseX && mouseX >= 80 + i*130)       
            obiecte[i+6].descend = true;       
    }
    
    // drag and drop
    if (button == GLFW_MOUSE_BUTTON_2 && mouseY >= 20 && 120 >= mouseY && 150 >= mouseX && mouseX >= 50)
    {
        scroll = true;
        x_diamond = mouseX;
        y_diamond = 720 - mouseY;
        
        nume = "diamond1";
        unu = true;
        doi = trei = patru = false;

    }
    else if(button == GLFW_MOUSE_BUTTON_2 && mouseY >= 20 && 120 >= mouseY && 310 >= mouseX && mouseX >= 210) 
    {
        scroll = true;
        x_diamond = mouseX;
        y_diamond = 720 - mouseY;
        
        nume = "diamond2";
        doi = true;
        unu = trei = patru = false;
    }
    else if (button == GLFW_MOUSE_BUTTON_2 && mouseY >= 20 && 120 >= mouseY && 470 >= mouseX && mouseX >= 370)
    {
        scroll = true;
        x_diamond = mouseX;
        y_diamond = 720 - mouseY;
        
        nume = "diamond3";
        trei = true;
        unu = doi = patru = false;
    }
    else if (button == GLFW_MOUSE_BUTTON_2 && mouseY >= 20 && 120 >= mouseY && 630 >= mouseX && mouseX >= 530)
    {
        scroll = true;
        x_diamond = mouseX;
        y_diamond = 720 - mouseY;
       
        nume = "diamond4";
        patru = true;
        unu = doi = trei = false;
    }

}


void Lab3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // plasarea romburilor in casute
    if (scroll == true && button == GLFW_MOUSE_BUTTON_2 && mouseY >= 600 && 700 >= mouseY && 180 >= mouseX && mouseX >= 80) { //0
        x_diamond = -50;
        y_diamond = -50;

        if (obiecte[0].exists == false) {
            if (unu == true && money >= 1) {
                obiecte[0].name = "diamond1";
                obiecte[0].x = 130;
                obiecte[0].y = 70;

                scroll = false;
                obiecte[0].exists = true;
                obiecte[0].descend = false;
                obiecte[0].sx_diamond = 1;
                obiecte[0].sy_diamond = 1;
                money -= 1;
            }
            else if (doi == true && money >= 2) {
                obiecte[0].name = "diamond2";
                obiecte[0].x = 130;
                obiecte[0].y = 70;
          
                scroll = false;
                obiecte[0].exists = true;
                obiecte[0].descend = false;
                obiecte[0].sx_diamond = 1;
                obiecte[0].sy_diamond = 1;
                money -= 2;
            }
            else if (trei == true && money >= 2) {
                obiecte[0].name = "diamond3";      
                obiecte[0].x = 130;
                obiecte[0].y = 70;
             
                scroll = false;
                obiecte[0].exists = true;
                obiecte[0].descend = false;
                obiecte[0].sx_diamond = 1;
                obiecte[0].sy_diamond = 1;
                money -= 2;
            }
            else if (patru == true && money >= 3) {
                obiecte[0].name = "diamond4";           
                obiecte[0].x = 130;
                obiecte[0].y = 70;
        
                scroll = false;
                obiecte[0].exists = true;
                obiecte[0].descend = false;
                obiecte[0].sx_diamond = 1;
                obiecte[0].sy_diamond = 1;
                money -= 3;
            }
        }
        scroll = false;

    }
    else if (scroll == true && button == GLFW_MOUSE_BUTTON_2 && mouseY >= 600 && 700 >= mouseY && 310 >= mouseX && mouseX >= 210) { //1
        x_diamond = -50;
        y_diamond = -50;

        if (obiecte[1].exists == false) {
            if (unu == true && money >= 1) {
                obiecte[1].name = "diamond1";          
                obiecte[1].x = 260;
                obiecte[1].y = 70;
             
                scroll = false;
                obiecte[1].exists = true;
                obiecte[1].descend = false;
                obiecte[1].sx_diamond = 1;
                obiecte[1].sy_diamond = 1;
                money -= 1;
            }
            else if (doi == true && money >= 2) {
                obiecte[1].name = "diamond2";         
                obiecte[1].x = 260;
                obiecte[1].y = 70;
       
                scroll = false;
                obiecte[1].exists = true;
                obiecte[1].descend = false;
                obiecte[1].sx_diamond = 1;
                obiecte[1].sy_diamond = 1;
                money -= 2;
            }
            else if (trei == true && money >= 2) {
                obiecte[1].name = "diamond3";             
                obiecte[1].x = 260;
                obiecte[1].y = 70;
         
                scroll = false;
                obiecte[1].exists = true;
                obiecte[1].descend = false;
                obiecte[1].sx_diamond = 1;
                obiecte[1].sy_diamond = 1;
                money -= 2;
            }
            else if (patru == true && money >= 3) {
                obiecte[1].name = "diamond4";
                obiecte[1].x = 260;
                obiecte[1].y = 70;
    
                scroll = false;
                obiecte[1].exists = true;
                obiecte[1].descend = false;
                obiecte[1].sx_diamond = 1;
                obiecte[1].sy_diamond = 1;
                money -= 3;
            }
        }
        scroll = false;
    }
    else if (scroll == true && button == GLFW_MOUSE_BUTTON_2 && mouseY >= 600 && 700 >= mouseY && 440 >= mouseX && mouseX >= 340) { //2
        x_diamond = -50;
        y_diamond = -50;

        if (obiecte[2].exists == false) {
            if (unu == true && money >= 1) {
                obiecte[2].name = "diamond1";              
                obiecte[2].x = 390;
                obiecte[2].y = 70;
           
                scroll = false;
                obiecte[2].exists = true;
                obiecte[2].descend = false;
                obiecte[2].sx_diamond = 1;
                obiecte[2].sy_diamond = 1;
                money -= 1;
            }
            else if (doi == true && money >= 2) {
                obiecte[2].name = "diamond2";              
                obiecte[2].x = 390;
                obiecte[2].y = 70;
                
                scroll = false;
                obiecte[2].exists = true;
                obiecte[2].descend = false;
                obiecte[2].sx_diamond = 1;
                obiecte[2].sy_diamond = 1;
                money -= 2;
            }
            else if (trei == true && money >= 2) {
                obiecte[2].name = "diamond3";
                obiecte[2].x = 390;
                obiecte[2].y = 70;

                scroll = false;
                obiecte[2].exists = true;
                obiecte[2].descend = false;
                obiecte[2].sx_diamond = 1;
                obiecte[2].sy_diamond = 1;
                money -= 2;
            }
            else if (patru == true && money >= 3) {
                obiecte[2].name = "diamond4";
                obiecte[2].x = 390;
                obiecte[2].y = 70;

                scroll = false;
                obiecte[2].exists = true;
                obiecte[2].descend = false;
                obiecte[2].sx_diamond = 1;
                obiecte[2].sy_diamond = 1;
                money -= 3;
            }
        }
        scroll = false;
    }
    else if (scroll == true && button == GLFW_MOUSE_BUTTON_2 && mouseY >= 450 && 550 >= mouseY && 180 >= mouseX && mouseX >= 80) { //3
        x_diamond = -50;
        y_diamond = -50;

        if (obiecte[3].exists == false) {
            if (unu == true && money >= 1) {
                obiecte[3].name = "diamond1";
                obiecte[3].x = 130;
                obiecte[3].y = 220;

                scroll = false;
                obiecte[3].exists = true;
                obiecte[3].descend = false;
                obiecte[3].sx_diamond = 1;
                obiecte[3].sy_diamond = 1;
                money -= 1;
            }
            else if (doi == true && money >= 2) {
                obiecte[3].name = "diamond2";
                obiecte[3].x = 130;
                obiecte[3].y = 220;

                scroll = false;
                obiecte[3].exists = true;
                obiecte[3].descend = false;
                obiecte[3].sx_diamond = 1;
                obiecte[3].sy_diamond = 1;
                money -= 2;
            }
            else if (trei == true && money >= 2) {
                obiecte[3].name = "diamond3";
                obiecte[3].x = 130;
                obiecte[3].y = 220;

                scroll = false;
                obiecte[3].exists = true;
                obiecte[3].descend = false;
                obiecte[3].sx_diamond = 1;
                obiecte[3].sy_diamond = 1;
                money -= 2;
            }
            else if (patru == true && money >= 3) {
                obiecte[3].name = "diamond4";
                obiecte[3].x = 130;
                obiecte[3].y = 220;

                scroll = false;
                obiecte[3].exists = true;
                obiecte[3].descend = false;
                obiecte[3].sx_diamond = 1;
                obiecte[3].sy_diamond = 1;
                money -= 3;
            }
        }
        scroll = false;
    }
    else if (scroll == true && button == GLFW_MOUSE_BUTTON_2 && mouseY >= 450 && 550 >= mouseY && 310 >= mouseX && mouseX >= 210) { //4
        x_diamond = -50;
        y_diamond = -50;

        if (obiecte[4].exists == false) {
            if (unu == true && money >= 1) {
                obiecte[4].name = "diamond1";
                obiecte[4].x = 260;
                obiecte[4].y = 220;

                scroll = false;
                obiecte[4].exists = true;
                obiecte[4].descend = false;
                obiecte[4].sx_diamond = 1;
                obiecte[4].sy_diamond = 1;
                money -= 1;
            }
            else if (doi == true && money >= 2) {
                obiecte[4].name = "diamond2";
                obiecte[4].x = 260;
                obiecte[4].y = 220;

                scroll = false;
                obiecte[4].exists = true;
                obiecte[4].descend = false;
                obiecte[4].sx_diamond = 1;
                obiecte[4].sy_diamond = 1;
                money -= 2;
            }
            else if (trei == true && money >= 2) {
                obiecte[4].name = "diamond3";
                obiecte[4].x = 260;
                obiecte[4].y = 220;

                scroll = false;
                obiecte[4].exists = true;
                obiecte[4].descend = false;
                obiecte[4].sx_diamond = 1;
                obiecte[4].sy_diamond = 1;
                money -= 2;
            }
            else if (patru == true && money >= 3) {
                obiecte[4].name = "diamond4";
                obiecte[4].x = 260;
                obiecte[4].y = 220;

                scroll = false;
                obiecte[4].exists = true;
                obiecte[4].descend = false;
                obiecte[4].sx_diamond = 1;
                obiecte[4].sy_diamond = 1;
                money -= 2;
            }
        }
        scroll = false;
    }
    else if (scroll == true && button == GLFW_MOUSE_BUTTON_2 && mouseY >= 450 && 550 >= mouseY && 440 >= mouseX && mouseX >= 340) { //5
        x_diamond = -50;
        y_diamond = -50;

        if (obiecte[5].exists == false) {
            if (unu == true && money >= 1) {
                obiecte[5].name = "diamond1";
                obiecte[5].x = 390;
                obiecte[5].y = 220;

                scroll = false;
                obiecte[5].exists = true;
                obiecte[5].descend = false;
                obiecte[5].sx_diamond = 1;
                obiecte[5].sy_diamond = 1;
                money -= 1;
            }
            else if (doi == true && money >= 2) {
                obiecte[5].name = "diamond2";
                obiecte[5].x = 390;
                obiecte[5].y = 220;

                scroll = false;
                obiecte[5].exists = true;
                obiecte[5].descend = false;
                obiecte[5].sx_diamond = 1;
                obiecte[5].sy_diamond = 1;
                money -= 2;
            }
            else if (trei == true && money >= 2) {
                obiecte[5].name = "diamond3";
                obiecte[5].x = 390;
                obiecte[5].y = 220;

                scroll = false;
                obiecte[5].exists = true;
                obiecte[5].descend = false;
                obiecte[5].sx_diamond = 1;
                obiecte[5].sy_diamond = 1;
                money -= 2;
            }
            else if (patru == true && money >= 3) {
                obiecte[5].name = "diamond4";
                obiecte[5].x = 390;
                obiecte[5].y = 220;

                scroll = false;
                obiecte[5].exists = true;
                obiecte[5].descend = false;
                obiecte[5].sx_diamond = 1;
                obiecte[5].sy_diamond = 1;
                money -= 3;
            }
        }
        scroll = false;
    }
    else if (scroll == true && button == GLFW_MOUSE_BUTTON_2 && mouseY >= 300 && 400 >= mouseY && 180 >= mouseX && mouseX >= 80) { //6
        x_diamond = -50;
        y_diamond = -50;

        if (obiecte[6].exists == false) {
            if (unu == true && money >= 1) {
                obiecte[6].name = "diamond1";
                obiecte[6].x = 130;
                obiecte[6].y = 370;

                scroll = false;
                obiecte[6].exists = true;
                obiecte[6].descend = false;
                obiecte[6].sx_diamond = 1;
                obiecte[6].sy_diamond = 1;
                money -= 1;
            }
            else if (doi == true && money >= 2) {
                obiecte[6].name = "diamond2";
                obiecte[6].x = 130;
                obiecte[6].y = 370;

                scroll = false;
                obiecte[6].exists = true;
                obiecte[6].descend = false;
                obiecte[6].sx_diamond = 1;
                obiecte[6].sy_diamond = 1;
                money -= 2;
            }
            else if (trei == true && money >= 2) {
                obiecte[6].name = "diamond3";
                obiecte[6].x = 130;
                obiecte[6].y = 370;

                scroll = false;
                obiecte[6].exists = true;
                obiecte[6].descend = false;
                obiecte[6].sx_diamond = 1;
                obiecte[6].sy_diamond = 1;
                money -= 2;
            }
            else if (patru == true && money >= 3) {
                obiecte[6].name = "diamond4";
                obiecte[6].x = 130;
                obiecte[6].y = 370;

                scroll = false;
                obiecte[6].exists = true;
                obiecte[6].descend = false;
                obiecte[6].sx_diamond = 1;
                obiecte[6].sy_diamond = 1;
                money -= 3;
            }
        }
        scroll = false;
    }
    else if (scroll == true && button == GLFW_MOUSE_BUTTON_2 && mouseY >= 300 && 400 >= mouseY && 310 >= mouseX && mouseX >= 210) { //7
        x_diamond = -50;
        y_diamond = -50;


        if (obiecte[7].exists == false) {
            if (unu == true && money >= 1) {
                obiecte[7].name = "diamond1";
                obiecte[7].x = 260;
                obiecte[7].y = 370;

                scroll = false;
                obiecte[7].exists = true;
                obiecte[7].descend = false;
                obiecte[7].sx_diamond = 1;
                obiecte[7].sy_diamond = 1;
                money -= 1;
            }
            else if (doi == true && money >= 2) {
                obiecte[7].name = "diamond2";
                obiecte[7].x = 260;
                obiecte[7].y = 370;

                scroll = false;
                obiecte[7].exists = true;
                obiecte[7].descend = false;
                obiecte[7].sx_diamond = 1;
                obiecte[7].sy_diamond = 1;
                money -= 2;
            }
            else if (trei == true && money >= 2) {
                obiecte[7].name = "diamond3";
                obiecte[7].x = 260;
                obiecte[7].y = 370;

                scroll = false;
                obiecte[7].exists = true;
                obiecte[7].descend = false;
                obiecte[7].sx_diamond = 1;
                obiecte[7].sy_diamond = 1;
                money -= 2;
            }
            else if (patru == true && money >= 3) {
                obiecte[7].name = "diamond4";
                obiecte[7].x = 260;
                obiecte[7].y = 370;

                scroll = false;
                obiecte[7].exists = true;
                obiecte[7].descend = false;
                obiecte[7].sx_diamond = 1;
                obiecte[7].sy_diamond = 1;
                money -= 3;
            }
        }
        scroll = false;
    }
    else if (scroll == true && button == GLFW_MOUSE_BUTTON_2 && mouseY >= 300 && 400 >= mouseY && 440 >= mouseX && mouseX >= 340) { //8
        x_diamond = -50;
        y_diamond = -50;

        if (obiecte[8].exists == false) {
            if (unu == true && money >= 1) {
                obiecte[8].name = "diamond1";
                obiecte[8].x = 390;
                obiecte[8].y = 370;

                scroll = false;
                obiecte[8].exists = true;
                obiecte[8].descend = false;
                obiecte[8].sx_diamond = 1;
                obiecte[8].sy_diamond = 1;
                money -= 1;
            }
            else if (doi == true && money >= 2) {
                obiecte[8].name = "diamond2";
                obiecte[8].x = 390;
                obiecte[8].y = 370;

                scroll = false;
                obiecte[8].exists = true;
                obiecte[8].descend = false;
                obiecte[8].sx_diamond = 1;
                obiecte[8].sy_diamond = 1;
                money -= 2;
            }
            else if (trei == true && money >= 2) {
                obiecte[8].name = "diamond3";
                obiecte[8].x = 390;
                obiecte[8].y = 370;

                scroll = false;
                obiecte[8].exists = true;
                obiecte[8].descend = false;
                obiecte[8].sx_diamond = 1;
                obiecte[8].sy_diamond = 1;
                money -= 2;
            }
            else if (patru == true && money >= 3) {
                obiecte[8].name = "diamond4";
                obiecte[8].x = 390;
                obiecte[8].y = 370;

                scroll = false;
                obiecte[8].exists = true;
                obiecte[8].descend = false;
                obiecte[8].sx_diamond = 1;
                obiecte[8].sy_diamond = 1;
                money -= 3;
            }
        }
        scroll = false;
    }
    else
    {
        x_diamond = -50;
        y_diamond = -50;
        scroll = false;
    }
}


void Lab3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Lab3::OnWindowResize(int width, int height)
{
}
