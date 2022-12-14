#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>
#include <queue>
using namespace std;



struct Edge {
    double threshold;
    
    //where the edge is pointing to (will be vert_num)
    int dest;

    //this will be set to blank at default
    std::string label;

    //common characteristic
};

struct Vertex {
    //this int will help identify what vertex we're looking at
    int vert_num;
    //insert characteristics
    double dancebility;
    double acousticness;
    double energy;
    std::string song_name;

    //this will be blank at default
    std::string label;

    //have each vertex hold its edges
    std::vector<Edge> edges;
};


class Graph {
    public:
        Graph();
        bool contains(std::vector<std::string> my_vec, std::string item_looking);
        void insertVertices(string filename, string filewrite);
        void translateData(const std::string& datainput, const std::string& dataoutput);

        void SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);


        void insertVertex(Vertex v);
        void insertEdge(int v1, int v2);

        //getting vertex, vertices, and the adjacent vertices of selected vertex
        Vertex findVertex(int vert_num);
        std::vector<Vertex> getVertices();
        vector<vector<string>> vertexToString();
        std::vector<Vertex> getAdjacents(Vertex v);

        //label functions for setting label for vertex and edges
        std::string getLabel(Vertex v);
        void setLabel(Vertex& v, std::string label_str);
        std::string getLabel(Edge e);
        void setLabel(Edge& e, std::string label_str);
        std::string getLabel(Vertex v, Vertex w);
        void setLabel(Vertex& v, Vertex& w, std::string label_str);
        
        void convertToAdjacencyList(vector<vector<int>> adjacencyMatrix);
        vector<vector<int>> getAdjacencyList();
        vector<vector<int>> getAdjacencyMatrix();
        void setAdjacencyMatrix(int size);
        map<pair<string, string>, double> getEdgesToHuesDance();
        map<pair<string, string>, double> getEdgesToHuesAcc();
        map<pair<string, string>, double> getEdgesToHuesEnergy();

        void makeEdgeHueMapDance(int size);
        void makeEdgeHueMapAcc(int size);
        void makeEdgeHueMapEnergy(int size);

        void changeHue(string song1, string song2, string factor);

        std::vector<string> getAllSongTitles();
        std::vector<double> getAllSongDance();
        std::vector<double> getAllSongAcc();
        std::vector<double> getAllSongEnergy();
        
        double getDancebility(string song);
        double getAcousticness(string song);
        double getEnergy(string song);

        void removeVertex(int vert_num);
        void removeEdgeDance(int vert_num1, int vert_num2);
        void removeEdgeAcc(int vert_num1, int vert_num2);
        void removeEdgeEnergy(int vert_num1, int vert_num2);


        int BFSTraversal();



    private:
        std::vector<Vertex> vertices;
        map<pair<string, string>, double> edges_to_hues_dance;
        map<pair<string, string>, double> edges_to_hues_acc;
        map<pair<string, string>, double> edges_to_hues_energy;

        vector<vector<int>> adjacency_matrix;
        vector<vector<int>> adjacencyList;

        std::vector<string> all_songs;
        std::vector<double> all_dance;
        std::vector<double> all_acc;
        std::vector<double> all_energy;

        void helperBFS(Vertex v, int& num_nodes);
};

string getSongRecommendation(Graph& g, string& songTitle, const string& category);