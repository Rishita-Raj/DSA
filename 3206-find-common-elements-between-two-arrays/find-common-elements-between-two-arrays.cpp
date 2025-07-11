class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int cnt1 = 0, cnt2 = 0;
        for(int i=0;i<nums1.size();i++){
            int key = nums1[i];
            for(int j=0;j<nums2.size();j++){
                if(key == nums2[j]){
                    cnt1++;
                    break;
                }
            }
        }
        for(int i=0;i<nums2.size();i++){
            int key = nums2[i];
            for(int j=0;j<nums1.size();j++){
                if(key == nums1[j]){
                    cnt2++;
                    break;
                }
            }
        }
        return {cnt1, cnt2};
    }
};