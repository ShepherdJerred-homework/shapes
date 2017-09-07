#include "stdafx.h"
#include "Image.h"
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "RightTriangle.h"
#include "Diamond.h"
#include "Star.h"
#include "json.hpp"
#include <string>

using json = nlohmann::json;

void createTestShapes(bool drawShadow) {
    Image image(100, 100, Color(0, 0, 0));

    Point point(Color(0, 255, 0), Coordinate(5, 5));
    point.draw(image, drawShadow);

    Line line(Color(255, 0, 0), Coordinate(10, 10), Coordinate(90, 90));
    line.draw(image, drawShadow);

    Rectangle rectangle(Color(0, 0, 255), Coordinate(10, 90), Coordinate(90, 10));
    rectangle.draw(image, drawShadow);

    Circle circle(Color(255, 255, 255), Coordinate(50, 50), 19);
    circle.draw(image, drawShadow);

    vector<Coordinate> points;
    points.push_back(Coordinate(10, 20));
    points.push_back(Coordinate(30, 40));
    points.push_back(Coordinate(10, 90));
    points.push_back(Coordinate(60, 30));
    points.push_back(Coordinate(30, 10));
    Polygon polygon(Color(155, 155, 155), points);
    polygon.draw(image, drawShadow);

    RightTriangle triangle(Color(100, 255, 50), Coordinate(20, 80), Coordinate(80, 20));
    triangle.draw(image, drawShadow);

    Diamond diamond(Color(50, 150, 50), Coordinate(80, 80), 10);
    diamond.draw(image, drawShadow);

    Star star(Color(200, 200, 200), Coordinate(50, 80), 15);
    star.draw(image, drawShadow);

    image.writeToFile("input.jpg");
}

void createFromJson(string fileName) {

    std::ifstream i(fileName + ".json");
    json j;
    i >> j;

    int imageWidth = j["image"]["size"]["width"];
    int imageHeight = j["image"]["size"]["height"];
    Color imageColor(j["image"]["background"]["red"], j["image"]["background"]["green"], j["image"]["background"]["blue"]);

    Image image(imageWidth, imageHeight, imageColor);

    vector<Shape*> shapes;

    for (auto entry : j["shapes"]) {
        Shape* shape;
        Color color(entry["color"]["red"], entry["color"]["green"], entry["color"]["blue"]);
        bool shadow = entry["shadow"];
        string type = entry["type"];

        if (type == "circle") {
            Coordinate center(entry["center"]["x"], entry["center"]["y"]);
            shape = new Circle(color, center, entry["radius"]);
            cout << "Created circle" << endl;

        } else if (type == "diamond") {
            Coordinate center(entry["center"]["x"], entry["center"]["y"]);
            shape = new Diamond(color, center, entry["size"]);
            cout << "Created diamond" << endl;

        } else if (type == "line") {
            Coordinate start(entry["start"]["x"], entry["start"]["y"]);
            Coordinate end(entry["end"]["x"], entry["end"]["y"]);
            shape = new Line(color, start, end);
            cout << "Created line" << endl;

        } else if (type == "point") {
            Coordinate coordinate(entry["coordinate"]["x"], entry["coordinate"]["y"]);
            shape = new Point(color, coordinate);
            cout << "Created point" << endl;

        } else if (type == "polygon") {
            vector<Coordinate> points;
            for (auto point : entry["points"]) {
                Coordinate coordinate(point["x"], point["y"]);
                points.push_back(coordinate);
            }
            shape = new Polygon(color, points);
            cout << "Created polygon" << endl;

        } else if (type == "rectangle") {
            Coordinate x(entry["x"]["x"], entry["x"]["y"]);
            Coordinate y(entry["y"]["x"], entry["y"]["y"]);
            shape = new Rectangle(color, x, y);
            cout << "Created rectangle" << endl;

        } else if (type == "righttriangle") {
            Coordinate x(entry["x"]["x"], entry["x"]["y"]);
            Coordinate y(entry["y"]["x"], entry["y"]["y"]);
            shape = new RightTriangle(color, x, y);
            cout << "Created right triangle" << endl;

        } else if (type == "star") {
            Coordinate center(entry["center"]["x"], entry["center"]["y"]);
            shape =  new Star(color, center, entry["size"]);
            cout << "Created star" << endl;

        } else {
            cout << "Invalid shape " << type;
            continue;
        }
        shape->draw(image, shadow);
        delete shape;
    }

    image.writeToFile((fileName + ".jpg").c_str());
}

int main() {
    //    createTestShapes(image, true);
    createFromJson("input");
    system("mspaint input.jpg");
    return 0;
}
