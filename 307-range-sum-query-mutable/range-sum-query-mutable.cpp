class NumArray {
public:
    vector<int> Tree;
    int n;

    NumArray(vector<int>& arr) {
        n = arr.size();
        Tree.resize(4 * n);
        buildTree(0, 0, n - 1, arr);
    }
    void buildTree(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            Tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;

        buildTree(2 * node + 1, start, mid, arr);
        buildTree(2 * node + 2, mid + 1, end, arr);

        Tree[node] = Tree[2 * node + 1] + Tree[2 * node + 2];
    }

    void updateQuery(int node, int start, int end, int index, int val) {
        if (start == end) {
            Tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;

        if (index <= mid) {
            updateQuery(2 * node + 1, start, mid, index, val);
        } else {
            updateQuery(2 * node + 2, mid + 1, end, index, val);
        }

        Tree[node] = Tree[2 * node + 1] + Tree[2 * node + 2];
    }
    void update(int index, int val) { updateQuery(0, 0, n - 1, index, val); }

    int rangeQuery(int node, int start, int end, int left, int right) {
        // 1.not inside
        if (right < start || left > end) {
            return 0;
        }
        // 2.completely inside
        if (start >= left && end <= right) {
            return Tree[node];
        }
        // 3.partially
        int mid = start + (end - start) / 2;

        int leftsum = rangeQuery(2 * node + 1, start, mid, left, right);
        int rightsum = rangeQuery(2 * node + 2, mid + 1, end, left, right);

        return leftsum + rightsum;
    }
    int sumRange(int left, int right) {
        return rangeQuery(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */