struct county {
  std::string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
};

struct state {
  std::string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
  struct county* counties;
  int n_counties;
};

struct state* allocate_states(int);

void read_state_data(struct state*, int, std::ifstream&);


struct county* allocate_counties(int);

void read_county_data(struct county*, int n, std::ifstream&);



void free_state_data(struct state*, int);

int display_choices(struct state*, int);

int display_choices_states(struct state*, int);

int display_choices_specific(struct county*, int, std::string);



struct state* seek_state_highest_income(struct state*,int);
struct state* seek_state_lowest_income(struct state*,int);

struct state* seek_state_highest_unemployment(struct state*,int);
struct state* seek_state_lowest_unemployment(struct state*,int);


struct county* seek_county_highest_income(struct county*,int);
struct county* seek_county_lowest_income(struct county*,int);

struct county* seek_county_highest_unemployment(struct county*,int);
struct county* seek_county_lowest_unemployment(struct county*,int);


struct state* sort_state_unemployment_change(struct state*, int);
struct state* sort_state_income_change(struct state*, int);

struct county* sort_county_unemployment_change(struct county*, int);
struct county* sort_county_income_change(struct county*, int);


bool sort_function_state_unemployment_change(struct state*, int);
bool sort_function_state_income_change(struct state*, int);

bool sort_function_county_unemployment_change(struct county*, int);
bool sort_function_county_income_change(struct county*, int);
