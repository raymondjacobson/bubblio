class BubblesController < ApplicationController
  #before_filter :get_real_url
  def new
    @bubble = Bubble.new(params[:bubble])
    @bubble.save
    @items = @bubble.items.order("happened_at DESC")
    @item = @items.build

  end

  def show
    @bubbles = Bubble.all
    id = get_real_url(request.url)
    if id==-1
      @bubble = Bubble.find(params[:id])
    else
  	  @bubble = Bubble.find(id)
    end
    @items = @bubble.items.order("happened_at DESC")
    @item = @items.build
    @links = @bubble.links.order("happened_at DESC")
    @link = @links.build
  end

  def create
  	@bubble = Bubble.new(params[:bubble])
  	if @bubble.save
      flash[:success] = "Bubble created!"
      redirect_to bubble_path(@bubble)
    else
      render 'new'
    end
  end

  def destroy
    @bubble = Bubble.find(params[:id])
    @bubble.destroy
    redirect_to root_path
  end

end
