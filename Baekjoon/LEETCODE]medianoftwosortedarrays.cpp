class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> total(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), total.begin());
        if(total.size()%2==1){
            return (double) total[total.size()/2];
        } else{
            return ((double) total[total.size()/2] + (double)total[total.size()/2 - 1]) / 2;
        }
    }
};