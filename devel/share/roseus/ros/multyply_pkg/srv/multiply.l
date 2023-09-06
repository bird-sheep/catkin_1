;; Auto-generated. Do not edit!


(when (boundp 'multyply_pkg::multiply)
  (if (not (find-package "MULTYPLY_PKG"))
    (make-package "MULTYPLY_PKG"))
  (shadow 'multiply (find-package "MULTYPLY_PKG")))
(unless (find-package "MULTYPLY_PKG::MULTIPLY")
  (make-package "MULTYPLY_PKG::MULTIPLY"))
(unless (find-package "MULTYPLY_PKG::MULTIPLYREQUEST")
  (make-package "MULTYPLY_PKG::MULTIPLYREQUEST"))
(unless (find-package "MULTYPLY_PKG::MULTIPLYRESPONSE")
  (make-package "MULTYPLY_PKG::MULTIPLYRESPONSE"))

(in-package "ROS")





(defclass multyply_pkg::multiplyRequest
  :super ros::object
  :slots (_a _b ))

(defmethod multyply_pkg::multiplyRequest
  (:init
   (&key
    ((:a __a) 0.0)
    ((:b __b) 0.0)
    )
   (send-super :init)
   (setq _a (float __a))
   (setq _b (float __b))
   self)
  (:a
   (&optional __a)
   (if __a (setq _a __a)) _a)
  (:b
   (&optional __b)
   (if __b (setq _b __b)) _b)
  (:serialization-length
   ()
   (+
    ;; float64 _a
    8
    ;; float64 _b
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _a
       (sys::poke _a (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _b
       (sys::poke _b (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _a
     (setq _a (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _b
     (setq _b (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass multyply_pkg::multiplyResponse
  :super ros::object
  :slots (_c ))

(defmethod multyply_pkg::multiplyResponse
  (:init
   (&key
    ((:c __c) 0.0)
    )
   (send-super :init)
   (setq _c (float __c))
   self)
  (:c
   (&optional __c)
   (if __c (setq _c __c)) _c)
  (:serialization-length
   ()
   (+
    ;; float64 _c
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _c
       (sys::poke _c (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _c
     (setq _c (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass multyply_pkg::multiply
  :super ros::object
  :slots ())

(setf (get multyply_pkg::multiply :md5sum-) "2b01e33a056883fbaa2d039561342da0")
(setf (get multyply_pkg::multiply :datatype-) "multyply_pkg/multiply")
(setf (get multyply_pkg::multiply :request) multyply_pkg::multiplyRequest)
(setf (get multyply_pkg::multiply :response) multyply_pkg::multiplyResponse)

(defmethod multyply_pkg::multiplyRequest
  (:response () (instance multyply_pkg::multiplyResponse :init)))

(setf (get multyply_pkg::multiplyRequest :md5sum-) "2b01e33a056883fbaa2d039561342da0")
(setf (get multyply_pkg::multiplyRequest :datatype-) "multyply_pkg/multiplyRequest")
(setf (get multyply_pkg::multiplyRequest :definition-)
      "float64 a
float64 b
---
float64 c
")

(setf (get multyply_pkg::multiplyResponse :md5sum-) "2b01e33a056883fbaa2d039561342da0")
(setf (get multyply_pkg::multiplyResponse :datatype-) "multyply_pkg/multiplyResponse")
(setf (get multyply_pkg::multiplyResponse :definition-)
      "float64 a
float64 b
---
float64 c
")



(provide :multyply_pkg/multiply "2b01e33a056883fbaa2d039561342da0")


