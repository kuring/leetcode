class LRUCache{
private:
	struct LRUUnit
	{
		int key;
		int value;
		LRUUnit(int key, int value) : key(key), value(value) {}
	};
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (lru_map.find(key) == lru_map.end())
		{
			return -1;
		}
		lru_list.splice(lru_list.begin(), lru_list, lru_map[key]);
		lru_map[key] = lru_list.begin();
		return lru_map[key]->value;
    }
    
    void set(int key, int value) {
        if (lru_map.find(key) == lru_map.end())
		{
			// 没有该节点
			if (lru_map.size() == capacity)
			{
				// 更新最后一个节点，并将节点放到最开始地方
				lru_list.end()->key = key;
				lru_list.end()->value = value;
				lru_list.splice(lru_list.begin(), lru_list, lru_list.end());
			}
			else
			{
				LRUUnit unit(key, value);
				lru_list.push_front(unit);
				lru_map[key] = lru_list.front();
			}
		}
		else
		{
			// 更新节点
			lru_map[key]->value = value;
			lru_list.splice(lru_list.begin(), lru_list, lru_map[key]);
			lru_map[key] = lru_list.begin();
		}
    }
	
private:
	int capacity;
	std::list<LRUUnit> lru_list; 
	std::map<int key, std::list<LRUUnit>::iterator> lru_map;
};