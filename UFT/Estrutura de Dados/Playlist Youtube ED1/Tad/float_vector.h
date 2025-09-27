

typedef struct float_vector FloatVector;


FloatVector * create(int capacity);
void destroy(FloatVector**vec);

int size(const FloatVector * vec);
int capacity(const FloatVector * vec);
float at(const FloatVector * vec);
float get(const FloatVector * vec);
void append(FloatVector * vec, float val);
void set(FloatVector * vec,int index, float val);
void print(const FloatVector * vec);

