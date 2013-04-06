# == Schema Information
#
# Table name: items
#
#  id         :integer          not null, primary key
#  created_at :datetime         not null
#  updated_at :datetime         not null
#  file       :string(255)
#  bubble_id  :integer
#

class Item < ActiveRecord::Base
  # attr_accessible :title, :body
  attr_accessible :file
  
  validates_presence_of :bubble_id, :file

  belongs_to :bubble

  mount_uploader :file, FileUploader
end
