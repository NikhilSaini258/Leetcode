class SnapshotArray {
    int snapId = 0;
    vector<map<int, int>> vm; // [index, {snap-ID, value}]
public:
    SnapshotArray(int length) {
        vm.resize (length);
        for (int i = 0; i < length; i++) {
            vm[i][snapId] = 0;
        }
    }
    
    void set(int index, int val) {
        vm[index][snapId] = val;
    }
    
    int snap() {
        snapId++;
        return snapId - 1;
    }
    
    int get(int index, int snap_id) {
        auto itr = vm[index].lower_bound (snap_id);
        if (itr == vm[index].end() || itr->first > snap_id) itr--;
        return itr->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
