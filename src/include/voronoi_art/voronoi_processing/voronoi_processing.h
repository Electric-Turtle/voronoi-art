/*
 * voronoi_processing.h
 *
 *  Created on: Nov 22, 2017
 *      Author: trent
 */

#ifndef INCLUDE_VORONOI_PROCESSING_H_
#define INCLUDE_VORONOI_PROCESSING_H_
#include <opencv/cv.hpp>
#include <boost/polygon/voronoi.hpp>
#include "voronoi_art/image_processing/pixel.h"

namespace voronoi_art {
using namespace std;
using namespace cv;
using namespace boost::polygon;

typedef voronoi_diagram<double> VD;
typedef double coordinate_type;
typedef point_data<coordinate_type> point_type;
class voronoi_processing {
public:

	voronoi_processing(const Mat& input_image,
			const std::vector<point_type>& site_points);
	virtual ~voronoi_processing();

	void draw_edges(Mat& out_image) const;
	void draw_cells(Mat& image) const;

	static cv_float_point voronoi_vertex_to_cv_point(const VD::vertex_type* vertex);
	static point_type cv_point_to_voronoi(const cv_float_point& pt);
	static vector<cv_float_point> voronoi_cell_to_cv_float_polygon(const VD::cell_type cell);
	static vector<cv_int_point> voronoi_cell_to_cv_int_polygon(const VD::cell_type cell);


	const voronoi_art::VD* get_voronoi_diagram() const;
	const std::vector<point_type>& get_site_points() const;

protected:
	virtual void draw_edge(voronoi_art::VD::const_edge_iterator& edge, Mat& image) const;
	virtual void draw_cell(voronoi_art::VD::const_cell_iterator& cell, vector<Pixel>& pixels_copy, Mat& image) const;

	voronoi_art::VD* vd_;
	std::vector<point_type> site_points_;
	std::vector<Pixel> input_image_pixels_;
	std::map<unsigned int, std::vector<Pixel> > cell_map_;
	Mat input_image_;
};

} /* namespace voronoi_art */

#endif /* INCLUDE_VORONOI_PROCESSING_H_ */