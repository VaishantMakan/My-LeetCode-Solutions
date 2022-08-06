// Grokking method - 2 heaps

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    priority_queue<int> maxHeap; // for the 1st half of numbers that are smaller than or equal to the median 
    
    priority_queue<int, vector<int>, greater<int>> minHeap; // for 2nd half, where nums are greater than or equal to the median
        
    void addNum(int num) {
        
        if(maxHeap.empty() || maxHeap.top() >= num)
            maxHeap.push(num);
        else
            minHeap.push(num);
        
        if(maxHeap.size() > minHeap.size() + 1) // that means maxHeap has more than 1 extra elements than minHeap and hence we need to balance both the heaps such that either both heaps have same num of elements or maxHeap has 1 extra num than minHeap
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    double findMedian() {
        
        if(maxHeap.size() == minHeap.size()) // i.e even num of elements total 
        {
            return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
        }
    
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */