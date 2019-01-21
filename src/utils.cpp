#include "utils.h"
//单元测试时编写

//extern "C"
// {

struct module_state {
    PyObject *error;
};
// static struct PyModuleDef moduledef = {
//         NULL,
//         "pym",
//         NULL,
//         sizeof(struct module_state),
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         NULL
// };
void initpym()
{
    // PyObject* m=PyModule_Create(&moduledef);

}

int addnum(int i, int j) {
    return i + j;
}
cv::Mat GetImage(std::string fn)
{
	cv::Mat image = cv::imread(fn.c_str());
	if (!image.data)
	{
		return cv::Mat();
	}
	return image;
}

int SetImage(cv::Mat& mat)
{
	cv::imshow("CppImage",mat);
	return mat.cols * mat.rows * mat.channels();
}


class Pet
{
    public:
        Pet(const std::string &name, int hunger) : name(name), hunger(hunger) {}
        ~Pet() {}

        void go_for_a_walk() { hunger++; }
        const std::string &get_name() const { return name; }
        int get_hunger() const { return hunger; }

    private:
        std::string name;
        int hunger;
};


PYBIND11_MODULE(pym, m)
{
	m.doc() = "PythonCallCpp";

    m.def("addnum", &addnum);
	m.def("GetImage", &GetImage);
	m.def("SetImage", &SetImage);


 	// bindings to Pet class
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &, int>())
        .def("go_for_a_walk", &Pet::go_for_a_walk)
        .def("get_hunger", &Pet::get_hunger)
        .def("get_name", &Pet::get_name);
	/*

	
	py::class_<cv::Mat>(m, "Image", py::buffer_protocol())
		.def_buffer([](cv::Mat& im) -> py::buffer_info {
		return py::buffer_info(
			// Pointer to buffer
			im.data,
			// Size of one scalar
			sizeof(unsigned char),
			// Python struct-style format descriptor
			py::format_descriptor<unsigned char>::format(),
			// Number of dimensions
			3,
			// Buffer dimensions
			{ im.rows, im.cols, im.channels() },
			// Strides (in bytes) for each index
				{
					sizeof(unsigned char) * im.channels() * im.cols,
					sizeof(unsigned char) * im.channels(),
					sizeof(unsigned char)
				}
				);
	});*/

}
// }