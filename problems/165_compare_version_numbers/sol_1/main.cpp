class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ver1_index = 0;
        int ver2_index = 0;
        while(ver1_index < version1.length() || ver2_index < version2.length())
        {
            int ver1 = 0;
            while(ver1_index < version1.length())
            {
                if(version1[ver1_index] == '.')
                {
                    ++ver1_index;
                    break;
                }

                ver1 = ver1 * 10 + (version1[ver1_index] - '0');
                ++ver1_index;
            }
            
            int ver2 = 0;
            while(ver2_index < version2.length())
            {
                if(version2[ver2_index] == '.')
                {
                    ++ver2_index;
                    break;
                }

                ver2 = ver2 * 10 + (version2[ver2_index] - '0');
                ++ver2_index;
            }

            if(ver1 > ver2)
                return 1;
            else if(ver1 < ver2)
                return -1;
        }

        return 0;
    }
};