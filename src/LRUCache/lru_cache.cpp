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
			// û�иýڵ�
			if (lru_map.size() == capacity)
			{
				// �������һ���ڵ㣬�����ڵ�ŵ��ʼ�ط�
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
			// ���½ڵ�
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