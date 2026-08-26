class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
       minHeap.push(num);

       if (!maxHeap.empty() and minHeap.top() < maxHeap.top()) {
          maxHeap.push(minHeap.top());
          minHeap.pop();
       }
       
       if (minHeap.size() > maxHeap.size() + 1) {
          maxHeap.push(minHeap.top());
          minHeap.pop();
       }
       
       if (maxHeap.size() > minHeap.size() + 1) {
          minHeap.push(maxHeap.top());
          maxHeap.pop();
       }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        if (maxHeap.size() > minHeap.size()) { return maxHeap.top();}
        if (maxHeap.size() < minHeap.size()) { return minHeap.top();}

    }
};
