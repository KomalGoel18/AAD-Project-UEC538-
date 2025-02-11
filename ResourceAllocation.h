#ifndef RESOURCE_ALLOCATION_H
#define RESOURCE_ALLOCATION_H

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Structure to represent a Virtual Machine (VM)
struct VM 
{
    string name;
    int cpu;
    int memory;
    int value; // Used in Knapsack algorithm
};

// Structure to represent a Server
struct Server 
{
    string name;
    int available_cpu;
    int available_memory;
};

class ResourceAllocator 
{
    public:
        unordered_map<string, VM> greedyAllocation(vector<VM>& vms, Server& server);
        int knapsackAllocation(vector<VM>& vms, int totalCpu);
        unordered_map<std::string, string> binPackingAllocation(vector<VM>& vms, vector<Server>& servers);
};

#endif