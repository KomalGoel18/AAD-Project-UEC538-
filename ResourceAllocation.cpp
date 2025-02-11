#include "resourceallocation.h"
using namespace std;

// Greedy Allocation
unordered_map<string, VM> ResourceAllocator::greedyAllocation(vector<VM>& vms, Server& server) 
{
    unordered_map<string, VM> allocation;

    // Sort VMs by CPU demand in descending order
    sort(vms.begin(), vms.end(), [](const VM& a, const VM& b) 
    {
        return a.cpu > b.cpu;
    });

    for (const auto& vm : vms) 
    {
        if (server.available_cpu >= vm.cpu && server.available_memory >= vm.memory) 
        {
            allocation[vm.name] = vm;
            server.available_cpu -= vm.cpu;
            server.available_memory -= vm.memory;
        }
    }
    return allocation;
}

// Knapsack Allocation (Dynamic Programming)
int ResourceAllocator::knapsackAllocation(std::vector<VM>& vms, int totalCpu) 
{
    int n = vms.size();
    vector<vector<int>> dp(n + 1, vector<int>(totalCpu + 1, 0));

    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 0; j <= totalCpu; ++j) 
        {
            if (vms[i - 1].cpu <= j) 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vms[i - 1].cpu] + vms[i - 1].value);
            } 
            else 
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][totalCpu];
}

// Bin Packing Allocation
unordered_map<std::string, std::string> ResourceAllocator::binPackingAllocation(vector<VM>& vms, vector<Server>& servers) 
{
    unordered_map<string, string> allocation;

    // Sort VMs by CPU demand in descending order
    sort(vms.begin(), vms.end(), [](const VM& a, const VM& b) 
    {
        return a.cpu > b.cpu;
    });

    for (const auto& vm : vms) 
    {
        for (auto& server : servers) 
        {
            if (server.available_cpu >= vm.cpu && server.available_memory >= vm.memory) 
            {
                allocation[vm.name] = server.name;
                server.available_cpu -= vm.cpu;
                server.available_memory -= vm.memory;
                break;
            }
        }
    }
    return allocation;
}