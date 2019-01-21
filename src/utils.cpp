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
PYBIND11_MODULE(pym, m)
{
	m.doc() = "PythonCallCpp";

    m.def("addnum", &addnum);
	m.def("GetImage", &GetImage);

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
	});

}
// }