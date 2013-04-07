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
require 'file_size_validator'
class Item < ActiveRecord::Base
  # attr_accessible :title, :body
  attr_accessible :file
  
  validates_presence_of :bubble_id

  belongs_to :bubble

  mount_uploader :file, FileUploader
  validates :file,
  	:presence => true,
  	:file_size => {
  		:maximum => 20.megabytes.to_i
  	}

  #one convenient method to pass jq_upload the necessary information
  def to_jq_upload
  {
    "id" => read_attribute(:id),
    "name" => read_attribute(:file),
    "size" => file.size,
    "url" => file.url,
    "delete_url" => picture_path(:id => id),
    "delete_type" => "DELETE" 
   }
  end

end
