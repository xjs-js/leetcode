/**
 * @date: 2020-03-20
 */ 

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();           // num of rooms
        int numOfVisitd = 0;            // num of visited rooms
        std::vector<bool> isRoomVisited(N, false);
        
        std::queue<int> keys({0});
        while (!keys.empty()) {
            // get the key
            int key = keys.front();
            keys.pop();

            if (isRoomVisited[key]) {
                continue;
            }
            else {
                isRoomVisited[key] = true;
                ++numOfVisitd;

                // enter in the room, get all keys in the room            
                std::vector<int>& keysInRoom = rooms.at(key);
                for (size_t i = 0; i < keysInRoom.size(); ++i) {
                    int k = keysInRoom[i];
                    if (isRoomVisited[k]) {
                        continue;
                    } else {
                        isRoomVisited[k] = true;
                        ++numOfVisitd;
                        
                        std::vector<int>& nextKeysInRoom = rooms.at(k);
                        for (size_t j = 0; j < nextKeysInRoom.size(); ++j) {
                            int n_k = nextKeysInRoom[j];
                            if (!isRoomVisited[n_k]) {
                                keys.push(n_k);
                            }
                        }
                    }
                }

                if (numOfVisitd == N) { 
                    return true;
                }
            }
        }
        
        return (numOfVisitd == N);
    }
};