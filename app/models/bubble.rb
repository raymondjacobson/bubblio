# == Schema Information
#
# Table name: bubbles
#
#  id         :integer          not null, primary key
#  title      :string(255)
#  created_at :datetime         not null
#  updated_at :datetime         not null
#

class Bubble < ActiveRecord::Base
  attr_accessible :title

  has_many :items, dependent: :destroy
  has_many :links, dependent: :destroy

end
