#pragma once

#include "components/simple_scene.h"
#include <string>
#include <vector>
#include <random>


namespace m1
{
    class Lab3 : public gfxc::SimpleScene
    {
     public:
        Lab3();
        ~Lab3();

        void Init() override;

     private:
        void CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices);
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        glm::mat3 modelMatrix;
        glm::ivec2 resolution;
        float angularStep;

        // life variable
        int lives;

        // hexagon variables
        float rh;

        typedef struct {
            float x;
            float y;
            float sx_hexagon;
            float sy_hexagon;
            int lives;
            std::string name;
            GLboolean exists;
            GLboolean descend;
        }Hexagoane;
        std::vector<Hexagoane> inamici;

        std::random_device random_period;
        std::mt19937 gen{ random_period() };
        std::uniform_real_distribution<float> dist_time{ 4.0f, 8.0f };
        float random_time;

        std::uniform_int_distribution<int> dist_indices{ 0, 2 };
        int lines[3] = { 70, 220, 370 };
        int index1;

        std::uniform_int_distribution<int> dist_names{ 1, 4 };
        int index2;
        GLboolean generate;
        

        // diamond variables
        float x_diamond, y_diamond;
        std::string nume;
        
        float rd;
        GLboolean scroll;
        
        typedef struct {
            float x;
            float y;
            float sx_diamond;
            float sy_diamond;
            std::string name;
            GLboolean exists; 
            GLboolean descend;
        }Romburi;
        Romburi obiecte[9];
        GLboolean unu, doi, trei, patru;

  
        // star variables
        float rs;
        typedef struct {
            float x;
            float y;
            float rs;
            std::string name;
            GLboolean exists; // se foloseste pt a verifica daca este un romb deja plasat in casuta
            GLboolean respawn;
        }Stars;
        std::vector<Stars> stars;
        float star_counter;


        // stelute colectabile
        typedef struct {
            float x;
            float y;
            float sx;
            float sy;
            float size;
            GLboolean exists;
        }Collectables;
        int money;
        std::vector<Collectables> collectables;

        std::random_device random_stars;
        std::mt19937 gen_star{ random_stars() };
        std::uniform_real_distribution<float> dist_star_time{ 10.0f, 15.0f };
        std::uniform_int_distribution<int> dist_starx{ 0, 1280};
        std::uniform_int_distribution<int> dist_stary{ 0, 720};
        float time_to_shine;
        
    };
}   // namespace m1
