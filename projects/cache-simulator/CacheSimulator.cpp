
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// One slot in the cache
struct CacheLine
{
    int blockAddress = -1;
    int lastUsed = -1;
    bool valid = false;
};

// Display all cache contents
void printCache(const vector<vector<CacheLine>>& cache)
{
    cout << "Cache contents:\n";

    for (int set = 0; set < (int)cache.size(); set++)
    {
        for (int way = 0; way < (int)cache[set].size(); way++)
        {
            cout << "Set " << set << ", Way " << way << ": ";

            if (cache[set][way].valid)
                cout << "Mem[" << cache[set][way].blockAddress << "]";
            else
                cout << "Empty";

            cout << "\n";
        }
    }
}

// Run the selected cache simulation
void simulateCache(int cacheBlocks, int ways,
    const vector<int>& addresses)
{
    int numSets = cacheBlocks / ways;

    vector<vector<CacheLine>> cache(
        numSets, vector<CacheLine>(ways));

    int hits = 0;
    int misses = 0;
    int clock = 0;

    for (int address : addresses)
    {
        clock++;

        // Determine which set the block belongs to
        int setIndex = address % numSets;

        bool hit = false;

        // Search all ways in the selected set
        for (int way = 0; way < ways; way++)
        {
            if (cache[setIndex][way].valid &&
                cache[setIndex][way].blockAddress == address)
            {
                hit = true;
                hits++;

                // Mark this block as recently used
                cache[setIndex][way].lastUsed = clock;
                break;
            }
        }

        if (hit)
        {
            cout << "\nBlock " << address << ": HIT!\n";
        }
        else
        {
            misses++;

            cout << "\nBlock " << address << ": MISS!\n";

            int replaceWay = -1;

            // First, look for an empty slot
            for (int way = 0; way < ways; way++)
            {
                if (!cache[setIndex][way].valid)
                {
                    replaceWay = way;
                    break;
                }
            }

            // If full, replace the least recently used block
            if (replaceWay == -1)
            {
                int oldestTime = numeric_limits<int>::max();

                for (int way = 0; way < ways; way++)
                {
                    if (cache[setIndex][way].lastUsed < oldestTime)
                    {
                        oldestTime = cache[setIndex][way].lastUsed;
                        replaceWay = way;
                    }
                }
            }

            cache[setIndex][replaceWay].blockAddress = address;
            cache[setIndex][replaceWay].lastUsed = clock;
            cache[setIndex][replaceWay].valid = true;
        }

        printCache(cache);
    }

    double missRate =
        (static_cast<double>(misses) / addresses.size()) * 100.0;

    cout << "\n===== Final Results =====\n";
    cout << "Total Hits: " << hits << "\n";
    cout << "Total Misses: " << misses << "\n";
    cout << "Miss Rate: " << missRate << "%\n";
}

int main()
{
    int cacheBlocks;
    int choice;
    int numReferences;

    cout << "===== CACHE SIMULATOR =====\n";

    cout << "Enter number of cache blocks: ";
    if (!(cin >> cacheBlocks) || cacheBlocks <= 0)
    {
        cout << "Invalid number of cache blocks.\n";
        return 1;
    }

    cout << "\nSelect cache organization:\n";
    cout << "1. Direct-Mapped\n";
    cout << "2. 2-Way Set Associative (LRU)\n";
    cout << "3. 4-Way Set Associative (LRU)\n";
    cout << "4. Fully Associative (LRU)\n";
    cout << "Enter choice: ";

    if (!(cin >> choice) || choice < 1 || choice > 4)
    {
        cout << "Invalid selection.\n";
        return 1;
    }

    int ways;

    if (choice == 1)
        ways = 1;
    else if (choice == 2)
        ways = 2;
    else if (choice == 3)
        ways = 4;
    else
        ways = cacheBlocks;

    if (cacheBlocks < ways || cacheBlocks % ways != 0)
    {
        cout << "Cache blocks must be divisible by the number of ways.\n";
        return 1;
    }





    if (choice == 1)
    {
        cout << "\nReplacement Policy: Not applicable (Direct-Mapped)\n";
    }
    else
    {
        int policy;

        cout << "\nSelect replacement policy:\n";
        cout << "1. LRU (Least Recently Used)\n";
        cout << "Enter choice: ";

        if (!(cin >> policy) || policy != 1)
        {
            cout << "Invalid replacement policy.\n";
            return 1;
        }

        cout << "Using LRU replacement policy.\n";
    }






    cout << "Enter number of memory references: ";

    if (!(cin >> numReferences) || numReferences <= 0)
    {
        cout << "Invalid number of references.\n";
        return 1;
    }

    vector<int> addresses;

    for (int i = 0; i < numReferences; i++)
    {
        int address;

        cout << "Enter block address " << i + 1 << ": ";

        if (!(cin >> address) || address < 0)
        {
            cout << "Invalid block address.\n";
            return 1;
        }

        addresses.push_back(address);
    }

    cout << "\n===== Simulation Started =====\n";

    simulateCache(cacheBlocks, ways, addresses);

    return 0;
}
