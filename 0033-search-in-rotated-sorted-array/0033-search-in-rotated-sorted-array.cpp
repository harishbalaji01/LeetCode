class Solution {
public:
int findpivot(vector<int>arr){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(s==e){
            return s;
        }
        if(mid<=e && arr[mid]>arr[mid+1]){//mid less than arr.size()
           
           return mid;
            
        }
        if(mid-1>=s && arr[mid-1]>arr[mid]){//condition for mid-1 is greter than 0
            
            return mid-1;
        }
        if(arr[s]>arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}
int binarysearch(vector<int>arr,int s,int e,int target){
    
    int mid=s+(e-s)/2;//(start+end)/2;
    while(s<=e){
        int element=arr[mid];
        if(element==target){
            return mid;
        }
        else if(target<element){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;//(start+end)/2;

    }
    return -1;//for denoting elemnt not found
    
}
    int search(vector<int>& nums, int target) {
        int pivotindex=findpivot(nums);
        int ans=0;
        if(target>=nums[0] && target<=nums[pivotindex]){
            ans=binarysearch(nums,0,pivotindex,target);
        }
        else{
            ans=binarysearch(nums,pivotindex+1,nums.size()-1,target);
        }


    return ans;
   }
};