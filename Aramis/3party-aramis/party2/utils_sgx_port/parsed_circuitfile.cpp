/*
Authors: Mayank Rathee.
Copyright:
Copyright (c) 2018 Microsoft Research
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "parsed_circuitfile.h"
extern const std::string circuit_string = "";
const int ckt_num_gate = 375;
const int ckt_num_wire = 439;
const int ckt_n1 = 32;
const int ckt_n2 = 32;
const int ckt_n3 = 33;
__m128i* ckt_wires = new __m128i[ckt_num_wire];
int ckt_gates[ckt_num_gate*4] = {0, 32, 406, 1, 5, 37, 373, 0, 4, 36, 336, 0, 10, 42, 340, 0, 14, 46, 366, 0, 24, 56, 341, 0, 8, 40, 342, 0, 1, 33, 343, 0, 7, 39, 348, 0, 28, 60, 349, 0, 19, 51, 350, 0, 2, 34, 351, 0, 30, 62, 364, 0, 13, 45, 352, 0, 18, 50, 353, 0, 11, 43, 355, 0, 3, 35, 356, 0, 16, 48, 359, 0, 31, 63, 357, 0, 27, 59, 358, 0, 15, 47, 360, 0, 17, 49, 361, 0, 9, 41, 363, 0, 32, 0, 278, 0, 29, 61, 362, 0, 6, 38, 365, 0, 25, 57, 354, 0, 20, 52, 367, 0, 22, 54, 331, 0, 21, 53, 371, 0, 12, 44, 372, 0, 23, 55, 339, 0, 26, 58, 368, 0, 56, 0, 398, 2, 3, 0, 314, 2, 40, 0, 346, 2, 62, 0, 378, 2, 6, 0, 389, 2, 28, 0, 401, 2, 10, 0, 377, 2, 13, 0, 391, 2, 27, 0, 335, 2, 7, 0, 387, 2, 24, 0, 399, 2, 54, 0, 327, 2, 36, 0, 315, 2, 52, 0, 332, 2, 50, 0, 380, 2, 57, 0, 404, 2, 31, 0, 323, 2, 55, 0, 317, 2, 18, 0, 381, 2, 60, 0, 400, 2, 5, 0, 322, 2, 14, 0, 395, 2, 47, 0, 402, 2, 8, 0, 347, 2, 19, 0, 385, 2, 53, 0, 374, 2, 29, 0, 330, 2, 1, 0, 382, 2, 34, 0, 344, 2, 20, 0, 333, 2, 37, 0, 321, 2, 45, 0, 390, 2, 11, 0, 338, 2, 42, 0, 376, 2, 12, 0, 370, 2, 38, 0, 388, 2, 23, 0, 318, 2, 41, 0, 392, 2, 61, 0, 329, 2, 15, 0, 403, 2, 48, 0, 396, 2, 26, 0, 320, 2, 43, 0, 337, 2, 59, 0, 334, 2, 9, 0, 393, 2, 58, 0, 319, 2, 17, 0, 326, 2, 44, 0, 369, 2, 21, 0, 375, 2, 49, 0, 325, 2, 16, 0, 397, 2, 25, 0, 405, 2, 51, 0, 384, 2, 4, 0, 316, 2, 2, 0, 345, 2, 39, 0, 386, 2, 46, 0, 394, 2, 35, 0, 313, 2, 22, 0, 328, 2, 63, 0, 324, 2, 33, 0, 383, 2, 30, 0, 379, 2, 313, 314, 282, 0, 315, 316, 283, 0, 317, 318, 284, 0, 319, 320, 299, 0, 321, 322, 285, 0, 323, 324, 286, 0, 325, 326, 288, 0, 327, 328, 289, 0, 329, 330, 290, 0, 331, 0, 130, 2, 332, 333, 287, 0, 334, 335, 292, 0, 336, 0, 256, 2, 337, 338, 293, 0, 339, 0, 123, 2, 340, 0, 214, 2, 341, 0, 116, 2, 342, 0, 228, 2, 343, 0, 276, 2, 344, 345, 310, 0, 346, 347, 300, 0, 348, 0, 235, 2, 349, 0, 88, 2, 350, 0, 151, 2, 351, 0, 270, 2, 352, 0, 193, 2, 353, 0, 158, 2, 354, 0, 109, 2, 355, 0, 207, 2, 356, 0, 263, 2, 357, 0, 66, 2, 358, 0, 95, 2, 359, 0, 172, 2, 360, 0, 179, 2, 361, 0, 165, 2, 362, 0, 81, 2, 363, 0, 221, 2, 364, 0, 74, 2, 365, 0, 242, 2, 366, 0, 186, 2, 367, 0, 144, 2, 368, 0, 102, 2, 369, 370, 301, 0, 371, 0, 137, 2, 372, 0, 200, 2, 373, 0, 249, 2, 374, 375, 298, 0, 376, 377, 296, 0, 378, 379, 291, 0, 380, 381, 297, 0, 382, 383, 306, 0, 384, 385, 294, 0, 386, 387, 295, 0, 388, 389, 302, 0, 390, 391, 303, 0, 392, 393, 304, 0, 394, 395, 305, 0, 396, 397, 307, 0, 398, 399, 308, 0, 400, 401, 309, 0, 402, 403, 311, 0, 404, 405, 312, 0, 282, 0, 266, 2, 283, 0, 259, 2, 284, 0, 126, 2, 285, 0, 252, 2, 286, 0, 69, 2, 287, 0, 147, 2, 288, 0, 168, 2, 289, 0, 133, 2, 290, 0, 84, 2, 291, 0, 77, 2, 292, 0, 98, 2, 293, 0, 210, 2, 294, 0, 154, 2, 295, 0, 238, 2, 296, 0, 217, 2, 297, 0, 161, 2, 298, 0, 140, 2, 299, 0, 105, 2, 300, 0, 231, 2, 301, 0, 203, 2, 302, 0, 245, 2, 303, 0, 196, 2, 304, 0, 224, 2, 305, 0, 189, 2, 306, 0, 281, 2, 307, 0, 175, 2, 308, 0, 119, 2, 309, 0, 91, 2, 310, 0, 273, 2, 311, 0, 182, 2, 312, 0, 112, 2, 281, 276, 277, 0, 69, 66, 279, 0, 281, 278, 280, 0, 277, 278, 407, 1, 279, 0, 71, 2, 280, 0, 275, 2, 275, 276, 274, 0, 274, 0, 271, 2, 2, 271, 268, 1, 271, 273, 272, 0, 34, 268, 408, 1, 272, 0, 269, 2, 269, 270, 267, 0, 267, 0, 264, 2, 3, 264, 261, 1, 264, 266, 265, 0, 35, 261, 409, 1, 265, 0, 262, 2, 262, 263, 260, 0, 260, 0, 257, 2, 4, 257, 253, 1, 257, 259, 258, 0, 36, 253, 410, 1, 258, 0, 255, 2, 255, 256, 254, 0, 254, 0, 250, 2, 5, 250, 247, 1, 250, 252, 251, 0, 37, 247, 411, 1, 251, 0, 248, 2, 248, 249, 246, 0, 246, 0, 243, 2, 6, 243, 239, 1, 243, 245, 244, 0, 38, 239, 412, 1, 244, 0, 241, 2, 241, 242, 240, 0, 240, 0, 236, 2, 7, 236, 233, 1, 236, 238, 237, 0, 39, 233, 413, 1, 237, 0, 234, 2, 234, 235, 232, 0, 232, 0, 229, 2, 8, 229, 226, 1, 229, 231, 230, 0, 40, 226, 414, 1, 230, 0, 227, 2, 227, 228, 225, 0, 225, 0, 222, 2, 9, 222, 219, 1, 222, 224, 223, 0, 41, 219, 415, 1, 223, 0, 220, 2, 220, 221, 218, 0, 218, 0, 215, 2, 10, 215, 212, 1, 215, 217, 216, 0, 42, 212, 416, 1, 216, 0, 213, 2, 213, 214, 211, 0, 211, 0, 208, 2, 11, 208, 205, 1, 208, 210, 209, 0, 43, 205, 417, 1, 209, 0, 206, 2, 206, 207, 204, 0, 204, 0, 201, 2, 12, 201, 198, 1, 201, 203, 202, 0, 44, 198, 418, 1, 202, 0, 199, 2, 199, 200, 197, 0, 197, 0, 195, 2, 13, 195, 190, 1, 195, 196, 194, 0, 45, 190, 419, 1, 194, 0, 192, 2, 192, 193, 191, 0, 191, 0, 187, 2, 14, 187, 183, 1, 187, 189, 188, 0, 46, 183, 420, 1, 188, 0, 185, 2, 185, 186, 184, 0, 184, 0, 180, 2, 15, 180, 177, 1, 180, 182, 181, 0, 47, 177, 421, 1, 181, 0, 178, 2, 178, 179, 176, 0, 176, 0, 173, 2, 48, 173, 170, 1, 173, 175, 174, 0, 16, 170, 422, 1, 174, 0, 171, 2, 171, 172, 169, 0, 169, 0, 166, 2, 17, 166, 163, 1, 166, 168, 167, 0, 49, 163, 423, 1, 167, 0, 164, 2, 164, 165, 162, 0, 162, 0, 159, 2, 18, 159, 156, 1, 159, 161, 160, 0, 50, 156, 424, 1, 160, 0, 157, 2, 157, 158, 155, 0, 155, 0, 152, 2, 19, 152, 149, 1, 152, 154, 153, 0, 51, 149, 425, 1, 153, 0, 150, 2, 150, 151, 148, 0, 148, 0, 145, 2, 20, 145, 141, 1, 145, 147, 146, 0, 52, 141, 426, 1, 146, 0, 143, 2, 143, 144, 142, 0, 142, 0, 138, 2, 53, 138, 135, 1, 138, 140, 139, 0, 21, 135, 427, 1, 139, 0, 136, 2, 136, 137, 134, 0, 134, 0, 132, 2, 22, 132, 127, 1, 132, 133, 131, 0, 54, 127, 428, 1, 131, 0, 129, 2, 129, 130, 128, 0, 128, 0, 124, 2, 23, 124, 121, 1, 124, 126, 125, 0, 55, 121, 429, 1, 125, 0, 122, 2, 122, 123, 120, 0, 120, 0, 117, 2, 24, 117, 114, 1, 117, 119, 118, 0, 56, 114, 430, 1, 118, 0, 115, 2, 115, 116, 113, 0, 113, 0, 110, 2, 25, 110, 107, 1, 110, 112, 111, 0, 57, 107, 431, 1, 111, 0, 108, 2, 108, 109, 106, 0, 106, 0, 103, 2, 26, 103, 100, 1, 103, 105, 104, 0, 58, 100, 432, 1, 104, 0, 101, 2, 101, 102, 99, 0, 99, 0, 96, 2, 59, 96, 93, 1, 96, 98, 97, 0, 27, 93, 433, 1, 97, 0, 94, 2, 94, 95, 92, 0, 92, 0, 89, 2, 28, 89, 86, 1, 89, 91, 90, 0, 60, 86, 434, 1, 90, 0, 87, 2, 87, 88, 85, 0, 85, 0, 83, 2, 61, 83, 79, 1, 83, 84, 82, 0, 29, 79, 435, 1, 82, 0, 80, 2, 80, 81, 78, 0, 78, 0, 76, 2, 30, 76, 72, 1, 76, 77, 75, 0, 62, 72, 436, 1, 75, 0, 73, 2, 73, 74, 70, 0, 70, 71, 437, 1, 70, 0, 68, 2, 68, 69, 67, 0, 67, 0, 65, 2, 65, 66, 64, 0, 64, 0, 438, 2};

/*File autogenerated by parse_circuitfile.py*/