#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>


void classement (std::string name, const float _time, std::vector<std::string> &tab_name, std::vector<float> &tab_score)
{
    std::ofstream Name("name.txt");
    std::ofstream Score("score.txt");
    float _score = _time;
    std::string line;
    //Writing names and score in text files
    if (Name)
    {
        Name << name << std::endl;
    }
    else
    {
        Name << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    if (Score)
    {
        Score << _score << std::endl;
    }
    else
    {
        Score << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    Name.close();
    std::ifstream Name_l("name.txt");

    for (int k = 0; k < tab_name.size(); k++)
    {
        while (std::getline(Name_l, line))
        {
            std::istringstream Name_line(line);

            for (int m = 0; m < tab_name.size() - 1; m++)
            {
                for (int n = 0; n < tab_name.size() - m - 1; n++)
                {
                    tab_name[n] = Name_line.str();
                }
            }
        }
    }
    Name_l.close();

    std::ifstream score_l("score.txt");

    for (int k = 0; k < tab_score.size(); k++)
    {
        while (std::getline(score_l, line))
        {
            std::istringstream score_line(line);

            for (int m = 0; m < tab_score.size() - 1; m++)
            {
                for (int n = 0; n < tab_score.size() - m - 1; n++)
                {
                    tab_score[n] = std::stof(score_line.str());
                }
            }
        }
    }
    Name_l.close();

    float tmp;
    std::string name_tmp;

    for (int i = 0; i < tab_score.size() - 1; i++)
    {
        for (int j = 0; j < tab_score.size() - i - 1; j++)
        {
            if (tab_score[j] > tab_score[j + 1])
            {
                tmp = tab_score[j];
                tab_score[j] = tab_score[j + 1];
                tab_score[j + 1] = tmp;

                name_tmp = tab_name[j];
                tab_name[j] = tab_name[j + 1];
                tab_name[j + 1] = name_tmp;
            }
        }
    }
}