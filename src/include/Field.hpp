
#include <thrust/device_vector.h>
#include <array>
#include <numeric>

template <typename val_type, int dim>
struct Field {

  typedef typename std::array<thrust::device_vector<val_type>,dim> field_t;
  typedef typename std::array<int,dim> fsize_t;

  field_t val;
  fsize_t field_size, bd_size, tot_size;

  Field(fsize_t field_size, fsize_t bd_size) :
  field_size(field_size), bd_size(bd_size) { 
    for (int i=0; i<dim; i++) 
      tot_size[i] = 2*bd_size[i] + field_size[i];
    
    int size_total = std::accumulate(tot_size.begin(),tot_size.end(),0);

    for (auto& elem : this->val) 
      elem.resize(size_total);
  }


};
