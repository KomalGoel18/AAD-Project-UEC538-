#include <iostream>
#include "resourceallocation.h"
using namespace std;

int main() 
{
    // Define a list of VMs
    vector<VM> vms = {{"VM1", 4, 8, 10},{"VM2", 2, 4, 5},{"VM3", 6, 12, 15},{"VM4", 1, 2, 2},{"VM5", 3, 6, 7}};

    // Define a server for Greedy and Knapsack
    Server server = {"Server1", 10, 20};

    ResourceAllocator allocator;

    // Greedy Allocation
    cout << "Greedy Allocation:\n";
    auto greedyAllocation = allocator.greedyAllocation(vms, server);
    for (const auto& entry : greedyAllocation) 
    {
        cout << "Allocated " << entry.first 
             << " (CPU: " << entry.second.cpu 
             << ", Memory: " << entry.second.memory << ")\n";
    }

    // Reset server resources for Knapsack
    server.available_cpu = 10;
    server.available_memory = 20;

    // Knapsack Allocation
    cout << "\nKnapsack Allocation (Max Utilization):\n";
    int maxUtilization = allocator.knapsackAllocation(vms, server.available_cpu);
    cout << "Maximum Resource Utilization: " << maxUtilization << "\n";

    // Define multiple servers for Bin Packing
    vector<Server> servers = {{"Server1", 10, 20},{"Server2", 8, 16}};

    // Bin Packing Allocation
    cout << "\nBin Packing Allocation:\n";
    auto binPackingAllocation = allocator.binPackingAllocation(vms, servers);
    for (const auto& entry : binPackingAllocation) 
    {
        cout << "Allocated " << entry.first << " to " << entry.second << "\n";
    }

    return 0;
}