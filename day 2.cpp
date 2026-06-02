QUES 1 MAXIMAUM SUBARRAY
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
QUES 2 CONTAIN DUBLICATES
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int num : nums) {
            if (s.count(num)) {
                return true;
            }
            s.insert(num);
        }

        return false;
    }
};
QUES 3 MAXIMUM AVERAGE SUBARRAY
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        long long windowSum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        long long maxSum = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};
OOPS PROBLEM  Create 2 classes “KidUsers” and “AdultUser” which implements the LibraryUser interface 
interface LibraryUser {
    void registerAccount();
    void requestBook();
}

class KidUsers implements LibraryUser {
    int age;
    String bookType;

    KidUsers(int age, String bookType) {
        this.age = age;
        this.bookType = bookType;
    }

    @Override
    public void registerAccount() {
        if (age < 12) {
            System.out.println("You have successfully registered under a Kids Account.");
        } else {
            System.out.println("Sorry, age must be less than 12 to register as a kid.");
        }
    }

    @Override
    public void requestBook() {
        if (bookType.equalsIgnoreCase("Kids")) {
            System.out.println("Book issued successfully, please return the book within 10 days.");
        } else {
            System.out.println("Oops, you are allowed to take only Kids books.");
        }
    }
}

class AdultUser implements LibraryUser {
    int age;
    String bookType;

    AdultUser(int age, String bookType) {
        this.age = age;
        this.bookType = bookType;
    }

    @Override
    public void registerAccount() {
        if (age >= 12) {
            System.out.println("You have successfully registered under an Adult Account.");
        } else {
            System.out.println("Sorry, age must be at least 12 to register as an adult.");
        }
    }

    @Override
    public void requestBook() {
        if (bookType.equalsIgnoreCase("Fiction")) {
            System.out.println("Book issued successfully, please return the book within 7 days.");
        } else {
            System.out.println("Oops, you are allowed to take only Fiction books.");
        }
    }
}

public class LibraryManagement {
    public static void main(String[] args) {

        KidUsers kid = new KidUsers(10, "Kids");
        kid.registerAccount();
        kid.requestBook();

        System.out.println();

        AdultUser adult = new AdultUser(25, "Fiction");
        adult.registerAccount();
        adult.requestBook();
    }
}
