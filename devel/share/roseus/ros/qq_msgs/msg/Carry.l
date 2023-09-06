;; Auto-generated. Do not edit!


(when (boundp 'qq_msgs::Carry)
  (if (not (find-package "QQ_MSGS"))
    (make-package "QQ_MSGS"))
  (shadow 'Carry (find-package "QQ_MSGS")))
(unless (find-package "QQ_MSGS::CARRY")
  (make-package "QQ_MSGS::CARRY"))

(in-package "ROS")
;;//! \htmlinclude Carry.msg.html


(defclass qq_msgs::Carry
  :super ros::object
  :slots (_grade _star _data ))

(defmethod qq_msgs::Carry
  (:init
   (&key
    ((:grade __grade) "")
    ((:star __star) 0)
    ((:data __data) "")
    )
   (send-super :init)
   (setq _grade (string __grade))
   (setq _star (round __star))
   (setq _data (string __data))
   self)
  (:grade
   (&optional __grade)
   (if __grade (setq _grade __grade)) _grade)
  (:star
   (&optional __star)
   (if __star (setq _star __star)) _star)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; string _grade
    4 (length _grade)
    ;; int32 _star
    4
    ;; string _data
    4 (length _data)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _grade
       (write-long (length _grade) s) (princ _grade s)
     ;; int32 _star
       (write-long _star s)
     ;; string _data
       (write-long (length _data) s) (princ _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _grade
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _grade (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int32 _star
     (setq _star (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _data
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _data (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get qq_msgs::Carry :md5sum-) "09435b551a188d60f45eb30f38b0f86f")
(setf (get qq_msgs::Carry :datatype-) "qq_msgs/Carry")
(setf (get qq_msgs::Carry :definition-)
      "string grade
int32 star
string data
")



(provide :qq_msgs/Carry "09435b551a188d60f45eb30f38b0f86f")


