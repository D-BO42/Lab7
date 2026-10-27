
void allocate();
void reallocate();
void quit();
int newvec(char name[8], float x, float y, float z);
struct vector addvec(char v1[8], char v2[8]);
struct vector subvec(char v1[8], char v2[8]);
struct vector getvector(char n[8]);
struct vector scaler(float s, char v1[8]);
void printVecs();
void clearVecs();
void save(char filename[50]);
void load(char filename[50]);