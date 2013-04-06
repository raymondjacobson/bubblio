# == Schema Information
#
# Table name: links
#
#  id          :integer          not null, primary key
#  hash        :string(255)
#  accessed_at :datetime
#  created_at  :datetime         not null
#  updated_at  :datetime         not null
#

class Link < ActiveRecord::Base
  attr_accessible :accessed_at, :hash

  belongs_to :bubble
end
